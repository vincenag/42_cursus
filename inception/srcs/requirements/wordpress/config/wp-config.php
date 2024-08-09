<?php
/** The name of the database for WordPress */
define( 'DB_NAME', __MARIADB_DATABASE__);
/** MySQL database username */
define( 'DB_USER', __MARIADB_USER__);
/** MySQL database password */
define( 'DB_PASSWORD', __MARIADB_PASSWORD__);
/** MySQL hostname */
define( 'DB_HOST', 'mariadb:3306');
/** Database charset to use in creating database tables. */
define( 'DB_CHARSET', 'utf8' );
/** The database collate type. Don't change this if in doubt. */
define( 'DB_COLLATE', '' );
/** Authentication unique keys and salts.*/
define('AUTH_KEY',         'P2tvGVT;X-N:QAfB}Wu+2GsuyvQ;Xnq |+O5Wbc-c)C.k/*_. ?y*{B9=3zp(RI=');
define('SECURE_AUTH_KEY',  '(~7+a)uDr+MTmF;@]rm-nw}P|&Q/eWqc|kH>z Z*+S>t;D~_3ecZc`9BKl|qi>S~');
define('LOGGED_IN_KEY',    'xfVv<u5|CF)kgQ@@@|PcU~c-}6:+V[+YvGtx{0.VmU4Tq3xj@,ZLhj:lgG}mj_TN');
define('NONCE_KEY',        'Shk^=wE?`8U|pE)EY-PNs`;C.F-44G_uq)|[VfdSf|_Gq+%h<da>UwXQKxK.:U[<');
define('AUTH_SALT',        'BK=>.1@$*l(`5+p1en/sUPnlW8l^mR[[+RH_5;.F2O6Z-&-tp1X56w[8,qyLhkc5');
define('SECURE_AUTH_SALT', 'DfI@`X%PT]uhksAYyVZe{Bb,l@@74{dI136Lt[-zN*7a-%BLD4;-$|}gs-Lx<`c$');
define('LOGGED_IN_SALT',   'p+4{1vPkQ=FTzdUodYMj?*!q:#qik_O)`n6dqS!yM5JzlfA`VS/I|S_Yc.2,:QXE');
define('NONCE_SALT',       '%Yck~f-xhD4*-N,dK5j~>h~6egSmG6dnh-<|4x@U?7rzt45+ukkuY9-|Y(j~V{Tw');
/** WordPress database table prefix.*/
$table_prefix = 'wp_';
/** For developers: WordPress debugging mode.*/
define( 'WP_DEBUG', true );
/* Add any custom values between this line and the "stop editing" line. */
/* That's all, stop editing! Happy publishing. */

/** Absolute path to the WordPress directory. */
if ( ! defined( 'ABSPATH' ) ) {
	define( 'ABSPATH', __DIR__ . '/' );
}

/** Sets up WordPress vars and included files. */
require_once ABSPATH . 'wp-settings.php';
?>