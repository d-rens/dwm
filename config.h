/* See LICENSE file for copyright and license details. */


/* Constants */
#define TERMINAL "st"
#define TERMCLASS "St"
#define BROWSER "firefox"

/* appearance */
static unsigned int borderpx        = 2;        /* border pixel of windows */
static unsigned int snap            = 32;       /* snap pixel */
static unsigned int gappih          = 10;       /* horiz inner gap between windows */
static unsigned int gappiv          = 10;       /* vert inner gap between windows */
static unsigned int gappoh          = 10;       /* horiz outer gap between windows and screen edge */
static unsigned int gappov          = 10;       /* vert outer gap between windows and screen edge */
static int swallowfloating          = 0;        /* 1 means swallow floating windows by default */
static int smartgaps                = 0;        /* 1 means no outer gap when there is only one window */
static int showbar                  = 1;        /* 0 means no bar */
static int topbar                   = 0;        /* 0 means bottom bar */
static char *fonts[]                = { "Maple Mono NF:size=12", "NotoColorEmoji:pixelsize=12:antialias=true:autohint=true"  };
static char normbgcolor[]           = "#f5f5dc"; // dmenu not selected (Beige)
static char normfgcolor[]           = "#4b4b4b"; // dmenu selected (Dark Gray)
static char normbordercolor[]       = "#dcdcdc"; // dwm border not active (Gainsboro)
static char selbordercolor[]        = "#a9a9a9"; // dwm border active (Dark Gray)
static char selfgcolor[]            = "#000000"; // fonts (Black)
/*static char normbgcolor[]           = "#00f00f"; // dmenu not selected*/
/*static char normfgcolor[]           = "#000077"; // dmenu selected*/
/*static char normbordercolor[]       = "#000000"; // dwm border not active*/
/*static char selbordercolor[]        = "#f0f000"; // dwm border active*/
/*static char selfgcolor[]            = "#ffffff"; // fonts*/
static char selbgcolor[]            = "#00f0f0"; // don't find it, now scurile color to find it
static char *colors[][3] = {
       /*               fg           bg           border   */
       [SchemeNorm] = { normfgcolor, normbgcolor, normbordercolor },
       [SchemeSel]  = { selfgcolor,  selbgcolor,  selbordercolor  },
};

typedef struct {
	const char *name;
	const void *cmd;
} Sp;
const char *spcmd1[] = {TERMINAL, "-n", "spterm", "-g", "120x34", NULL };
const char *spcmd2[] = {TERMINAL, "-n", "spcalc", "-f", "monospace:size=16", "-g", "50x20", "-e", "bc", "-lq", NULL };
static Sp scratchpads[] = {
	/* name          cmd  */
	{"spterm",      spcmd1},
	{"spcalc",      spcmd2},
};


/* tagging */
static const char *tags[] = { 
    /*
    "0-writing", 
    "1-prog", 
    "2-mesg", 
    "3-media", 
    "4-img-editing", 
    "5-bib", 
    "6-sec", 
    "7-web", 
    "8-BruteForcing" 
    "9-figuring" 
    */
    "📝",
    "💻",
    "✉️ ",
    "📷",
    "🎨",
    "📚",
    "🔒",
    "🌐",
    "🔐"
};


static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	*/
	/* class      instance      title       	 tags mask    isfloating   isterminal  noswallow  monitor */
    { "Element",    NULL,       NULL,             1 << 2,     0,           0,         0,          -1 },
    { "JabRef",     NULL,       NULL,             1 << 5,     0,           0,         0,          -1 },
    { "KeePassXC",  NULL,       NULL,             1 << 6,     0,           0,         0,          -1 },
    { "Monero",     NULL,       NULL,             1 << 6,     0,           0,         0,          -1 },
    { "Signal",     NULL,       NULL,             1 << 2,     0,           0,         0,          -1 },
    { "Tor Browser",NULL,       NULL,             1 << 7,     0,           0,         0,          -1 },
    { "VSCodium",   NULL,       NULL,             1 << 1,     0,           0,         0,          -1 },
    { "abook",      NULL,       NULL,             1 << 2,     0,           1,         0,          -1 },
    { "firefox",    NULL,       NULL,             1 << 7,     0,           0,         0,          -1 },
    { "gimp",       NULL,       NULL,       	  1 << 4,     0,           0,         0,          -1 },
    { "inkscape",   NULL,       NULL,       	  1 << 4,     0,           0,         0,          -1 },
    { "jabref",     NULL,       NULL,             1 << 5,     0,           0,         0,          -1 },
    { "mpv",        NULL,       NULL,             1 << 3,     0,           0,         0,          -1 },
    { "mutt",       NULL,       NULL,             1 << 2,     0,           1,         0,          -1 },
    { "ncmpcpp",    NULL,       NULL,             1 << 3,     0,           1,         0,          -1 },
    { "neomutt",    NULL,       NULL,             1 << 2,     0,           1,         0,          -1 },
    { "newsboat",   NULL,       NULL,             1 << 3,     0,           1,         0,          -1 },
  //{ "nvim",       NULL,       NULL,             1 << 1,     0,           1,         0,          -1 },
    { "obsidian",   NULL,       NULL,             1 << 0,     0,           0,         0,          -1 },
    { "smerge",     NULL,       NULL,             1 << 1,     0,           0,         0,          -1 },
    { "vscodium",   NULL,       NULL,             1 << 1,     0,           0,         0,          -1 },
    { "xournalpp",  NULL,       NULL,             1 << 0,     0,           0,         0,          -1 },
    { "zathura",    NULL,       NULL,             1 << 0,     0,           0,         0,          -1 },
    { "zotero",     NULL,       NULL,             1 << 5,     0,           0,         0,          -1 },
    { NULL,         NULL,       "Event Tester",   0,          0,           0,         1,          -1 },
    { TERMCLASS,    "bg",       NULL,       	  1 << 7,     0,           1,         0,          -1 },
    { TERMCLASS,    "floatterm",NULL,       	  0,          1,           1,         0,          -1 },
    { TERMCLASS,    "spcalc",   NULL,       	  SPTAG(1),   1,           1,         0,          -1 },
    { TERMCLASS,    "spterm",   NULL,       	  SPTAG(0),   1,           1,         0,          -1 },
    { TERMCLASS,    NULL,       NULL,       	  0,          0,           1,         0,          -1 },
};

/* layout(s) */
static float mfact     = 0.55; /* factor of master area size [0.05..0.95] */
static int nmaster     = 1;    /* number of clients in master area */
static int resizehints = 0;    /* 1 means respect size hints in tiled resizals */
static const int lockfullscreen = 1; /* 1 will force focus on the fullscreen window */

#define FORCE_VSPLIT 1  /* nrowgrid layout: force two clients to always split vertically */
#include "vanitygaps.c"

static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "[]=",	tile },			/* Default: Master on left, slaves on right */
	{ "TTT",	bstack },		/* Master on top, slaves on bottom */

	{ "[@]",	spiral },		/* Fibonacci spiral */
	{ "[\\]",	dwindle },		/* Decreasing in size right and leftward */

	{ "[D]",	deck },			/* Master on left, slaves in monocle-like mode on right */
	{ "[M]",	monocle },		/* All windows on top of eachother */

	{ "|M|",	centeredmaster },	/* Master in middle, slaves on sides */
	{ ">M>",	centeredfloatingmaster },/* Same but master floats */

	{ "><>",	NULL },			/* no layout function means floating behavior */
	{ NULL,		NULL },
};

/* key definitions */
#define MODKEY Mod1Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },
#define STACKKEYS(MOD,ACTION) \
	{ MOD,	XK_j,	ACTION##stack,	{.i = INC(+1) } }, \
	{ MOD,	XK_k,	ACTION##stack,	{.i = INC(-1) } }, \
	/* { MOD,  XK_v,   ACTION##stack,  {.i = 0 } }, \ what does this even do? */
	/* { MOD, XK_grave, ACTION##stack, {.i = PREVSEL } }, \ */
	/* { MOD, XK_a,     ACTION##stack, {.i = 1 } }, \ */
	/* { MOD, XK_z,     ACTION##stack, {.i = 2 } }, \ */
	/* { MOD, XK_x,     ACTION##stack, {.i = -1 } }, */

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static const char *termcmd[]  = { TERMINAL, NULL };

/*
 * Xresources preferences to load at startup
 */
ResourcePref resources[] = {
		{ "color0",		STRING,	&normbordercolor },
		{ "color8",		STRING,	&selbordercolor },
		{ "color0",		STRING,	&normbgcolor },
		{ "color4",		STRING,	&normfgcolor },
		{ "color0",		STRING,	&selfgcolor },
		{ "color4",		STRING,	&selbgcolor },
		{ "borderpx",		INTEGER, &borderpx },
		{ "snap",		INTEGER, &snap },
		{ "showbar",		INTEGER, &showbar },
		{ "topbar",		INTEGER, &topbar },
		{ "nmaster",		INTEGER, &nmaster },
		{ "resizehints",	INTEGER, &resizehints },
		{ "mfact",		FLOAT,	&mfact },
		{ "gappih",		INTEGER, &gappih },
		{ "gappiv",		INTEGER, &gappiv },
		{ "gappoh",		INTEGER, &gappoh },
		{ "gappov",		INTEGER, &gappov },
		{ "swallowfloating",	INTEGER, &swallowfloating },
		{ "smartgaps",		INTEGER, &smartgaps },
};

#include <X11/XF86keysym.h>
#include "shiftview.c"

static const Key keys[] = {
	/* modifier                     key        function        argument */
	/* { MODKEY|ShiftMask,		XK_Escape,	spawn,	SHCMD("") }, */
	/* { MODKEY|ShiftMask,		XK_grave,	togglescratch,	SHCMD("") }, */
	STACKKEYS(MODKEY,                          focus)
	STACKKEYS(MODKEY|ShiftMask,                push)
	TAGKEYS(			XK_1,		0)
	TAGKEYS(			XK_2,		1)
	TAGKEYS(			XK_3,		2)
	TAGKEYS(			XK_4,		3)
	TAGKEYS(			XK_5,		4)
	TAGKEYS(			XK_6,		5)
	TAGKEYS(			XK_7,		6)
	TAGKEYS(			XK_8,		7)
	TAGKEYS(			XK_9,		8)

	{ MODKEY,			XK_0,		view,		{.ui = ~0 } },
	{ MODKEY|ShiftMask, XK_0,		tag,		{.ui = ~0 } },
	{ MODKEY,	        XK_grave,	spawn,	{.v = (const char*[]){ "dmenuunicode", NULL } } },



    /* system */
    { MODKEY,           XK_F1,	    spawn,		SHCMD("wacom-monitor-selector") },
    { 0, XF86XK_AudioLowerVolume,	spawn,		SHCMD("pulsemixer --change-volume -5") },
    { 0, XF86XK_AudioMute,		    spawn,		SHCMD("pulsemixer --toggle-mute") },
    { 0, XK_Print,	                spawn,		SHCMD("maim ~/pi/full-$(date '+%y%m%d-%H%M-%S').png") },
    { 0, XF86XK_AudioRaiseVolume,	spawn,		SHCMD("pulsemixer --change-volume +5") },
    { MODKEY,           XK_Down,	spawn,		SHCMD("brightnessctl set 5%-") },
    { MODKEY,           XK_Up,	    spawn,		SHCMD("brightnessctl set 5%+") },



    /* dwm */
	{ MODKEY,			XK_Right,	    focusmon,	        {.i = +1 } },
	{ MODKEY,			XK_Tab,		    view,	            {0} },
	{ MODKEY,			XK_a,		    togglegaps,	        {0} },
	{ MODKEY,			XK_apostrophe,	togglescratch,	    {.ui = 1} },
	{ MODKEY,			XK_b,		    togglebar,	        {0} },
	{ MODKEY,			XK_f,		    togglefullscr,	    {0} },
	{ MODKEY,			XK_g,		    shiftview,	        { .i = -1 } },
	{ MODKEY,			XK_h,		    setmfact,	        {.f = -0.05} },
	{ MODKEY,			XK_i,		    setlayout,	        {.v = &layouts[6]} }, /* centeredmaster */
	{ MODKEY,			XK_l,		    setmfact,      	    {.f = +0.05} },
	{ MODKEY,			XK_q,		    killclient,	        {0} },
	{ MODKEY,			XK_semicolon,	shiftview,	        { .i = 1 } },
	{ MODKEY,			XK_space,	    zoom,		        {0} },
	{ MODKEY,			XK_t,		    setlayout,	        {.v = &layouts[0]} }, /* tile */
	{ MODKEY,			XK_u,		    setlayout,	        {.v = &layouts[4]} }, /* deck */
	{ MODKEY,			XK_y,		    setlayout,	        {.v = &layouts[2]} }, /* spiral */
	{ MODKEY,			XK_z,		    incrgaps,	        {.i = +3 } },
    { MODKEY,			XK_Left,	    focusmon,	        {.i = -1 } },
    { MODKEY,			XK_Page_Down,	shiftview,	        { .i = +1 } },
    { MODKEY,			XK_Page_Up,	    shiftview,	        { .i = -1 } },
	{ MODKEY|ShiftMask,	XK_Left,	    tagmon,		        {.i = -1 } },
	{ MODKEY|ShiftMask,	XK_Page_Down,	shifttag,	        { .i = +1 } },
	{ MODKEY|ShiftMask,	XK_Page_Up,	    shifttag,	        { .i = -1 } },
	{ MODKEY|ShiftMask,	XK_Return,	    togglescratch,	    {.ui = 0} },
	{ MODKEY|ShiftMask,	XK_Right,	    tagmon,		        {.i = +1 } },
	{ MODKEY|ShiftMask,	XK_a,		    defaultgaps,	    {0} },
	{ MODKEY|ShiftMask,	XK_apostrophe,	togglesmartgaps,	{0} },
	{ MODKEY|ShiftMask,	XK_f,		    setlayout,	        {.v = &layouts[8]} },
	{ MODKEY|ShiftMask,	XK_g,		    shifttag,	        { .i = -1 } },
	{ MODKEY|ShiftMask,	XK_semicolon,	shifttag,	        { .i = 1 } },
	{ MODKEY|ShiftMask,	XK_space,	    togglefloating,	    {0} },
	{ MODKEY|ShiftMask,	XK_x,		    incrgaps,	        {.i = -3 } },
	{ MODKEY|ShiftMask, XK_i,		    setlayout,	        {.v = &layouts[7]} }, /* centeredfloatingmaster */
	{ MODKEY|ShiftMask, XK_t,		    setlayout,	        {.v = &layouts[1]} }, /* bstack */
	{ MODKEY|ShiftMask, XK_u,		    setlayout,	        {.v = &layouts[5]} }, /* monocle */
	{ MODKEY|ShiftMask, XK_y,		    setlayout,	        {.v = &layouts[3]} }, /* dwindle */
    { MODKEY,			XK_o,		        incnmaster, {.i = +1 } },
    { MODKEY|ShiftMask, XK_o,		        incnmaster, {.i = -1 } },

    /* programs */
    { MODKEY,			XK_F4,		spawn,      SHCMD(TERMINAL " -e pulsemixer; kill -44 $(pidof dwmblocks)") },
    { MODKEY,			XK_Return,	spawn,      {.v = termcmd } },
    { MODKEY,			XK_m,		spawn,      {.v = (const char*[]){ TERMINAL, "-e", "ncmpcpp", NULL } } },
    { MODKEY,			XK_p,		spawn,		SHCMD(TERMINAL " -e calcurse") },
    { MODKEY,			XK_p,		spawn,		{.v = (const char*[]){ "mpc", "toggle", NULL } } },
    { MODKEY,			XK_r,		spawn,		{.v = (const char*[]){ TERMINAL, "-e", "lf", NULL } } },
    { MODKEY,			XK_w,		spawn,		{.v = (const char*[]){ BROWSER, NULL } } },
    { MODKEY|ShiftMask,	XK_d,		spawn,      {.v = (const char*[]){ "keepmenu", NULL } } },
    { MODKEY|ShiftMask,	XK_c,		spawn,      {.v = (const char*[]){ "keepassxc", NULL } } },
    { MODKEY|ShiftMask, XK_r,		spawn,		{.v = (const char*[]){ TERMINAL, "-e", "btop", NULL } } },
    { MODKEY,           XK_e,		spawn,		{.v = (const char*[]){ TERMINAL, "-e", "gomuks", NULL } } },
    { MODKEY|ShiftMask, XK_v,		spawn,		{.v = (const char*[]){ TERMINAL, "-e", "sudo", "nmtui", NULL } } },


    /* scripts */

    // lecture notes 
	{ MODKEY,       	XK_n,		    spawn,		SHCMD("figures a") },
	{ MODKEY|ShiftMask,	XK_e,		    spawn,		SHCMD("figures e") },
	{ MODKEY,       	XK_c,		    spawn,		SHCMD("figures c") },
	{ MODKEY,   	    XK_F2,		    spawn,		SHCMD("select-lecture") },


    // phd script
	{ MODKEY|ShiftMask,	XK_n,		    spawn,		SHCMD("st -e phd-shortcuts n") },
	//{ MODKEY,			XK_o,		    spawn,		SHCMD("phd-shortcuts o") },
	{ MODKEY,			XK_x,		    spawn,		SHCMD("phd-shortcuts x") },
	{ MODKEY|ShiftMask, XK_l,		    spawn,	    SHCMD("phd-shortcuts l") },
	{ MODKEY|ShiftMask, XK_p,		    spawn,	    SHCMD("phd-shortcuts p") },

    { MODKEY,			XK_F1,		    spawn,		SHCMD("semimak") },
    { MODKEY,			XK_F11,		    spawn,	    SHCMD("mpv --untimed --no-cache --no-osc --no-input-default-bindings --profile=low-latency --input-conf=/dev/null --title=webcam $(ls /dev/video[0,2,4,6,8] | tail -n 1)") },
    { MODKEY|ShiftMask, XK_w,		    spawn,		SHCMD("wallpaper-select") },

    { MODKEY,			XK_BackSpace,	spawn,		{.v = (const char*[]){ "sysact", NULL } } },
    { MODKEY|ShiftMask, XK_BackSpace,   spawn,	    {.v = (const char*[]){ "sysact", NULL } } },
    { MODKEY|ShiftMask, XK_q,		    spawn,		{.v = (const char*[]){ "sysact", NULL } } },
    { MODKEY,			XK_Delete,	    spawn,		{.v = (const char*[]){ "dmenurecord", "kill", NULL } } },
    { MODKEY,			XK_F10,		    spawn,		{.v = (const char*[]){ "unmounter", NULL } } },
    { MODKEY,			XK_F3,		    spawn,	    {.v = (const char*[]){ "displayselect", NULL } } },
    { MODKEY,			XK_F9,		    spawn,	    {.v = (const char*[]){ "mounter", NULL } } },
    { MODKEY,			XK_Print,	    spawn,	    {.v = (const char*[]){ "dmenurecord", NULL } } },
    { MODKEY,			XK_d,		    spawn,      {.v = (const char*[]){ "dmenu_run", NULL } } },
    { MODKEY|ShiftMask,	XK_Print,	    spawn,      {.v = (const char*[]){ "dmenurecord", "kill", NULL } } },
    { ShiftMask,		XK_Print,	    spawn,		{.v = (const char*[]){ "maimpick", NULL } } },



	/* don't have a use for the actions
	{ MODKEY,                       XK_o,      incrihgaps,     {.i = -1 } },
	{ MODKEY,                       XK_y,      incrihgaps,     {.i = +1 } },
	{ MODKEY|ControlMask,           XK_o,      incrivgaps,     {.i = -1 } },
	{ MODKEY|ControlMask,           XK_y,      incrivgaps,     {.i = +1 } },
	{ MODKEY|Mod4Mask,              XK_h,      incrgaps,       {.i = +1 } },
	{ MODKEY|Mod4Mask,              XK_l,      incrgaps,       {.i = -1 } },
	{ MODKEY|Mod4Mask,              XK_o,      incrohgaps,     {.i = -1 } },
	{ MODKEY|Mod4Mask,              XK_y,      incrohgaps,     {.i = +1 } },
	{ MODKEY|Mod4Mask|ControlMask,  XK_h,      incrigaps,      {.i = +1 } },
	{ MODKEY|Mod4Mask|ControlMask,  XK_l,      incrigaps,      {.i = -1 } },
	{ MODKEY|Mod4Mask|ShiftMask,    XK_0,      defaultgaps,    {0} },
	{ MODKEY|Mod4Mask|ShiftMask,    XK_h,      incrogaps,      {.i = +1 } },
	{ MODKEY|Mod4Mask|ShiftMask,    XK_l,      incrogaps,      {.i = -1 } },
	{ MODKEY|ShiftMask,		        XK_apostrophe,	spawn,		        SHCMD("") },
	{ MODKEY|ShiftMask,		        XK_b,		spawn,		        SHCMD("") },
	{ MODKEY|ShiftMask,		        XK_c,		spawn,		        SHCMD("") },
	{ MODKEY|ShiftMask,		        XK_x,		spawn,		        SHCMD("") },
	{ MODKEY|ShiftMask,		        XK_z,		spawn,		        SHCMD("") },
	{ MODKEY|ShiftMask,             XK_o,      incrovgaps,     {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_y,      incrovgaps,     {.i = +1 } },
    { 0, XF86XK_PowerOff,		spawn,		{.v = (const char*[]){ "sysact", NULL } } },
    */

    /* don't have the buttons
	{ 0, XF86XK_AudioMicMute,	spawn,		SHCMD("pactl set-source-mute @DEFAULT_SOURCE@ toggle") },
	{ 0, XF86XK_AudioNext,		spawn,		{.v = (const char*[]){ "mpc",  "next", NULL } } },
	{ 0, XF86XK_AudioPause,		spawn,		{.v = (const char*[]){ "mpc", "pause", NULL } } },
	{ 0, XF86XK_AudioPlay,		spawn,		{.v = (const char*[]){ "mpc", "play", NULL } } },
	{ 0, XF86XK_AudioPrev,		spawn,		{.v = (const char*[]){ "mpc", "prev", NULL } } },
	{ 0, XF86XK_AudioStop,		spawn,		{.v = (const char*[]){ "mpc", "stop", NULL } } },
    { 0, XF86XK_Calculator,		spawn,		{.v = (const char*[]){ TERMINAL, "-e", "bc", "-l", NULL } } },
    { 0, XF86XK_DOS,		spawn,		{.v = termcmd } },
    { 0, XF86XK_Launch1,		spawn,		{.v = (const char*[]){ "xset", "dpms", "force", "off", NULL } } },
    { 0, XF86XK_Mail,		spawn,		SHCMD(TERMINAL " -e neomutt ; pkill -RTMIN+12 dwmblocks") },
    { 0, XF86XK_MyComputer,		spawn,		{.v = (const char*[]){ TERMINAL, "-e",  "lfub",  "/", NULL } } },
    { 0, XF86XK_ScreenSaver,	spawn,		SHCMD("slock & xset dpms force off; mpc pause; pauseallmpv") },
    { 0, XF86XK_Sleep,		spawn,		{.v = (const char*[]){ "sudo", "-A", "zzz", NULL } } },
    { 0, XF86XK_TaskPane,		spawn,		{.v = (const char*[]){ TERMINAL, "-e", "htop", NULL } } },
    { 0, XF86XK_TouchpadOff,	spawn,		{.v = (const char*[]){ "synclient", "TouchpadOff=1", NULL } } },
    { 0, XF86XK_TouchpadOn,		spawn,		{.v = (const char*[]){ "synclient", "TouchpadOff=0", NULL } } },
    { 0, XF86XK_TouchpadToggle,	spawn,		SHCMD("(synclient | grep 'TouchpadOff.*1' && synclient TouchpadOff=0) || synclient TouchpadOff=1") },
    { 0, XF86XK_WWW,		spawn,		{.v = (const char*[]){ BROWSER, NULL } } },
	{ MODKEY,XK_Insert,	        spawn,      SHCMD("xdotool type $(grep -v '^#' ~/.local/share/larbs/snippets | dmenu -i -l 50 | cut -d' ' -f1)") },
	{ MODKEY,XK_Scroll_Lock,	spawn,      SHCMD("killall screenkey || screenkey &") },
    */


    /* don't have a use
    { MODKEY,			XK_F1,		        spawn,		SHCMD("zathura ~/.local/share/larbs-dwm.pdf") },
    { MODKEY,			XK_F2,		        spawn,		{.v = (const char*[]){ "tutorialvids", NULL } } },
    { MODKEY,			XK_F5,		        xrdb,		{.v = NULL } },
    { MODKEY,			XK_F6,		        spawn,		{.v = (const char*[]){ "torwrap", NULL } } },
    { MODKEY,			XK_F7,		        spawn,		{.v = (const char*[]){ "td-toggle", NULL } } },
    { MODKEY,			XK_F8,		        spawn,		{.v = (const char*[]){ "mailsync", NULL } } },
    { MODKEY,			XK_backslash,	    view,	    {0} },
    { MODKEY,			XK_bracketleft,	    spawn,	    {.v = (const char*[]){ "mpc", "seek", "-10", NULL } } },
    { MODKEY,			XK_bracketright,    spawn,	    {.v = (const char*[]){ "mpc", "seek", "+10", NULL } } },
    { MODKEY,			XK_c,		        spawn,		{.v = (const char*[]){ TERMINAL, "-e", "profanity", NULL } } }, // xmpp client
    { MODKEY,			XK_comma,	        spawn,		{.v = (const char*[]){ "mpc", "prev", NULL } } },
    { MODKEY,			XK_e,		        spawn,		SHCMD(TERMINAL " -e neomutt ; pkill -RTMIN+12 dwmblocks") },
    { MODKEY,			XK_equal,	        spawn,		SHCMD("wpctl set-volume @DEFAULT_AUDIO_SINK@ 5%+") },
    { MODKEY,			XK_minus,	        spawn,		SHCMD("wpctl set-volume @DEFAULT_AUDIO_SINK@ 5%-") },
    { MODKEY,			XK_period,	        spawn,		{.v = (const char*[]){ "mpc", "next", NULL } } },
    { MODKEY|ShiftMask,	XK_backslash,	    spawn,		SHCMD("") }, 
    { MODKEY|ShiftMask,	XK_comma,	        spawn,		{.v = (const char*[]){ "mpc", "seek", "0%", NULL } } },
    { MODKEY|ShiftMask,	XK_m,		        spawn,		SHCMD("wpctl set-mute @DEFAULT_AUDIO_SINK@ toggle; kill -44 $(pidof dwmblocks)") },
    { MODKEY|ShiftMask,	XK_n,		        spawn,		SHCMD(TERMINAL " -e newsboat ; pkill -RTMIN+6 dwmblocks") },
    { MODKEY|ShiftMask,	XK_period,	        spawn,		{.v = (const char*[]){ "mpc", "repeat", NULL } } },
    { MODKEY|ShiftMask,	XK_s,		        spawn,		SHCMD("") }, 
    { MODKEY|ShiftMask, XK_bracketleft,	    spawn,	    {.v = (const char*[]){ "mpc", "seek", "-60", NULL } } },
    { MODKEY|ShiftMask, XK_bracketright,    spawn,	    {.v = (const char*[]){ "mpc", "seek", "+60", NULL } } },
	{ 0, XF86XK_Battery,		            spawn,		SHCMD("") }, 
    { MODKEY|ShiftMask, XK_equal,	        spawn,		SHCMD("wpctl set-volume @DEFAULT_AUDIO_SINK@ 15%+") },
    { MODKEY|ShiftMask, XK_minus,	        spawn,		SHCMD("wpctl set-volume @DEFAULT_AUDIO_SINK@ 15%-") },
    */

};





/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static const Button buttons[] = {
	/* click                event mask      button          function        argument */
#ifndef __OpenBSD__
	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
	{ ClkStatusText,        0,              Button1,        sigdwmblocks,   {.i = 1} },
	{ ClkStatusText,        0,              Button2,        sigdwmblocks,   {.i = 2} },
	{ ClkStatusText,        0,              Button3,        sigdwmblocks,   {.i = 3} },
	{ ClkStatusText,        0,              Button4,        sigdwmblocks,   {.i = 4} },
	{ ClkStatusText,        0,              Button5,        sigdwmblocks,   {.i = 5} },
	{ ClkStatusText,        ShiftMask,      Button1,        sigdwmblocks,   {.i = 6} },
#endif
	{ ClkStatusText,        ShiftMask,      Button3,        spawn,          SHCMD(TERMINAL " -e nvim ~/.local/src/dwmblocks/config.h") },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        defaultgaps,	{0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkClientWin,		MODKEY,		Button4,	incrgaps,	{.i = +1} },
	{ ClkClientWin,		MODKEY,		Button5,	incrgaps,	{.i = -1} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
	{ ClkTagBar,		0,		Button4,	shiftview,	{.i = -1} },
	{ ClkTagBar,		0,		Button5,	shiftview,	{.i = 1} },
	{ ClkRootWin,		0,		Button2,	togglebar,	{0} },
};

