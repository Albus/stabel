CREATE SEQUENCE reg.reg_work_time_id_seq
  INCREMENT 1 MINVALUE 1
  MAXVALUE 9223372036854775807 START 1
  CACHE 1;

CREATE OR REPLACE FUNCTION public.tf__reg_work_time__b01u (
)
RETURNS trigger AS
$body$
BEGIN
  IF (OLD.time_end_client IS NULL) AND (NEW.time_end_client IS NOT NULL) THEN
    NEW.time_end_server = now();
  END IF;

  RETURN NEW;
END;
$body$
LANGUAGE 'plpgsql'
VOLATILE
CALLED ON NULL INPUT
SECURITY INVOKER
COST 100;

CREATE TABLE reg.reg_work_time (
  id INTEGER DEFAULT nextval('reg.reg_work_time_id_seq'::regclass) NOT NULL,
  time_begin_server TIMESTAMP(0) WITH TIME ZONE DEFAULT now() NOT NULL,
  time_begin_client TIMESTAMP(0) WITH TIME ZONE NOT NULL,
  time_begin_inet TIMESTAMP(0) WITH TIME ZONE,
  time_end_server TIMESTAMP(0) WITH TIME ZONE,
  time_end_client TIMESTAMP(0) WITH TIME ZONE,
  time_end_inet TIMESTAMP(0) WITH TIME ZONE,
  login_key VARCHAR(32) NOT NULL,
  is_night BOOLEAN NOT NULL,
  time_sended TIMESTAMP(0) WITH TIME ZONE,
  CONSTRAINT reg_work_time_pkey PRIMARY KEY(id)
) ;

ALTER TABLE reg.reg_work_time
  ALTER COLUMN time_end_server SET STATISTICS 0;

ALTER TABLE reg.reg_work_time
  ALTER COLUMN time_end_client SET STATISTICS 0;

ALTER TABLE reg.reg_work_time
  ALTER COLUMN time_end_inet SET STATISTICS 0;

COMMENT ON COLUMN reg.reg_work_time.id
IS 'ID';

COMMENT ON COLUMN reg.reg_work_time.time_begin_server
IS 'Время начала смены (по данным сервера БД)';

COMMENT ON COLUMN reg.reg_work_time.time_begin_client
IS 'Время начала смены (по данным клиента)';

COMMENT ON COLUMN reg.reg_work_time.time_begin_inet
IS 'Время начала смены (по данным сервера NTP)';

COMMENT ON COLUMN reg.reg_work_time.time_end_server
IS 'Время окончания смены (по данным сервера БД)';

COMMENT ON COLUMN reg.reg_work_time.time_end_client
IS 'Время окончания смены (по данным клиента)';

COMMENT ON COLUMN reg.reg_work_time.time_end_inet
IS 'Время окончания смены (по данным сервера NTP)';

COMMENT ON COLUMN reg.reg_work_time.login_key
IS 'Ключ доступа (бейдж сотрудника)';

COMMENT ON COLUMN reg.reg_work_time.is_night
IS 'Признак ночной смены';

COMMENT ON COLUMN reg.reg_work_time.time_sended
IS 'Время отправки данных в офис';

CREATE INDEX reg_work_time_idx ON reg.reg_work_time
  USING btree (id)
  WHERE (time_sended IS NULL);

CREATE UNIQUE INDEX reg_work_time_idx1 ON reg.reg_work_time
  USING btree (login_key COLLATE pg_catalog."default")
  WHERE (time_end_server IS NULL);

CREATE TRIGGER tr__reg_work_time__b01u
  BEFORE UPDATE OF time_end_client
  ON reg.reg_work_time FOR EACH ROW
  EXECUTE PROCEDURE public.tf__reg_work_time__b01u();

ALTER SEQUENCE reg.reg_work_time_id_seq OWNED BY reg.reg_work_time.id;
