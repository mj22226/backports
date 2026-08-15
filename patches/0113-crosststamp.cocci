@@
struct system_device_crosststamp *xtstamp;
expression systime;
@@
-xtstamp->sys_systime = systime;
+crosststamp_set_systime(xtstamp, systime);

@@
struct system_device_crosststamp *xtstamp;
@@
-xtstamp->clock_id
+crosststamp_clock_id(xtstamp)
