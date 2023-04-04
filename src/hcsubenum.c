/*
*
* hcsubenum.c - contains the subdomain_enumeration() command
* The Hconsole Project is made by Copy05
*
* (c) Copy05 2020-2023
*
* ~~~~~~~~~~~~~[ What is Subdomain Enumeration ]~~~~~~~~~~~~~~~~~~~~~~
*
* A subdomain enumeration is a method of finding subdomains of a domain
* It's used for hacking, security or if you're really curious how someone's site works
* 
* Why are there multiple subdomains?:
* They use multiple versions of the same subdomain to hide their site. or to avoid getting indexed by a search engine.
* 
* Education?:
* Check the subdomains array and learn where the subdomains are used for. 
*       (if you're a minor please skip the NSFW subdomains!)
* 
* ~~~~~~~~~~~~~[ What's our sources for the subdomains ]~~~~~~~~~~~~~~
* 
* https://lumendatabase.org/
* https://github.com/rbsec/dnscan/blob/master/subdomains-10000.txt
* https://github.com/RPiList/specials/
* https://www.google.com/
* https://www.nmmapper.com/sys/tools/subdomainfinder/
* 
* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~[ Author ]~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
* 
*   Copy05 [https://github.com/Copy05/]
*   MRAXXX [https://github.com/MRAXXX/]
*   const int* [https://github.com/ConstantesInt/]
* 
*/

#pragma warning(disable : 6262)

#include "hcsubenum.h"
#include "stdheads.h"

void subdomain_enumeration(const char* f, const char* opts)
{
    /* It's messy */
    char subdomains[][64] = {
        // [0.1] www protocols
        "www", "www1", "www2", "www3", "ww1", "ww2", "ww3", "ww4", "ww5", "ww6", "ww7", "wwwl", "wwl", "wwv", "wwv1", "wwv2", "wwv3",

        // [0.2] dev 0 - 30
        "dev0", "dev", "dev1", "dev2", "dev3", "dev4", "dev5", "dev6", "dev7", "dev8", "dev9", "dev10", "dev11", "dev12", "dev13", "dev14",
        "dev15", "dev16", "dev17", "dev18", "dev19", "dev20", "dev21", "dev22", "dev23", "dev24", "dev25", "dev26", "dev27", "dev28", "dev29", "dev30",

        // [0.3] ns 0 - 65
        "ns0", "ns", "ns1", "ns2", "ns3", "ns4", "ns5", "ns6", "ns7", "ns8", "ns9", "ns10", "ns11", "ns12", "ns13", "ns14", "ns15", "ns16",
        "ns17", "ns18", "ns19", "ns20", "ns21", "ns22", "ns23", "ns24", "ns25", "ns26", "ns27", "ns28", "ns29", "ns30", "ns31", "ns32",
        "ns33", "ns34", "ns35", "ns36", "ns37", "ns38", "ns39", "ns40", "ns41", "ns42", "ns43", "ns44", "ns45", "ns46", "ns47", "ns48",
        "ns49", "ns50", "ns51", "ns52", "ns53", "ns54", "ns55", "ns56", "ns57", "ns58", "ns59", "ns60", "ns61", "ns62", "ns63", "ns64", "ns65",

        // [0.4] mysql 0 - 40
        "mysql0", "mysql", "mysql1", "mysql2", "mysql3", "mysql4", "mysql5", "mysql6", "mysql7", "mysql8", "mysql9", "mysql10", "mysql11", "mysql12",
        "mysql13", "mysql14", "mysql15", "mysql16", "mysql17", "mysql18", "mysql19", "mysql20", "mysql21", "mysql22", "mysql23", "mysql24", "mysql25",
        "mysql26", "mysql27", "mysql28", "mysql29", "mysql30", "mysql31", "mysql32", "mysql33", "mysql34", "mysql35", "mysql36", "mysql37", "mysql38", "mysql39", "mysql40",

        // [0.5] dns 0 -  30
        "dns0", "dns", "dns1", "dns2", "dns3", "dns4", "dns5", "dns6", "dns7", "dns8", "dns9", "dns10", "dns11", "dns12", "dns13", "dns14", "dns15", "dns16", "dns17",
        "dns18", "dns19", "dns20", "dns21", "dns22", "dns23", "dns24", "dns25", "dns26", "dns27", "dns28", "dns29", "dns30",

        // [0.5.1] Node 0 - 10
        "node0", "node", "node1", "node2", "node3", "node4", "node5", "node6", "node7", "node8", "node9", "node10",

        // Serial 0 - 10
        "serial0", "serial", "serial1", "serial2", "serial3", "serial4", "serial5", "serial6", "serial7", "serial8", "serial9", "serial10",

        // Alphabet
        "a", "aa", "aaa", "aaaa", "aaaaa", "aaaaaa", "b", "c", "d", "e", "f", "g", "h", "j", "k", "l", "m", "n", "o", "p", "q", "r", "s", "t", "u", "v", "w", "x", "y", "z",

        // Numbers 0 - 20
        "0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "11", "12", "13", "14", "15", "16", "17", "18", "19", "20",
        "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten",

        // Years 2000 - 2026
        "2000", "2001", "2002", "2003", "2004", "2005", "2006", "2007", "2008", "2009", "2010", "2011", "2012", "2013", "2014", "2015", "2016", "2017", "2018", "2019", "2020",
        "2021", "2022", "2023", "2024", "2025", "2026",

        // [0.6] Most common subdomains
        "about", "mail", "news", "images", "img", "cdn", "ftp", "billing", "landing", "blog", "wiki", "web",

        // Admin
        "admin", "adm", "myadmin", "phpmyadmin", "phpmyadmin1", "phpmyadmin2", "phpmyadmin3", "phpmyadmin4",

        // [0.7] Databases
        "oracle", "azure", "sql", "sql1", "database", "mongodb", "dbadmin", "db", "docker", "mariadb",

        // [0.8] Store
        "shop", "store", "merch", "estore", "eshop", "order", "checkout", "cart", "pay", "shopping", "sale", "sales", "markt", "market", "marketplace", "deal", "deals", "dealling",
        "pricing", "shipping", "aparrel", "aparrell", "reseller", "resell", "your-orders", "manage-orders", "economy", "eco",

        // [0.9] other protocols
        "ssh", "ssl", "dhcp", "inet", "tcp", "voip", "ldap", "dcp", "p2p", "tor", "udp", "dtp", "smtp", "ntp", "proc",

        // [0.10] (I)nternet (P)rotocol
        "internet-protocol", "ip", "ipv4", "ipv6", "ip4", "ip5", "ips",

        // [0.11] Livestreaming
        "stream", "yt", "live", "tv0", "tv", "tv1", "tv2", "tv3", "tv4", "tv5", "iptv", "streaming", "sub",

        // [0.12] Carrier subdomains
        "carrier", "jobs", "work", "carriers", "works", "apply", "employ", "employment", "hireme",

        // [0.13] Mail
        "exchange", "email", "thunderbird", "mailer", "write", "newmail", "mail0", "mail1", "mail2", "mail3", "mail4", "mail5", "mail6", "mail7", "e-mail",

        // File Storages
        "drive", "dropbox", "static", "media", "photos", "video", "mirror", "archive", "pic", "gif", "scripts", "script", "documents", "mirrors", "source", "mega", "fileshare",

        // [0.15] cloud
        "cloud", "aws", "cloudflare",

        // [0.16] chat & call
        "meet", "call", "contact", "chat", "msg", "message", "messager", "slack", "conference",

        // Adverticements
        "promote", "ads", "promo", "promotion", "redirect", "ad", "traffic", "click", "clicked", "marketing", "opt", "adsense", "admob"

        // [0.18] Education
        "edu", "education", "academy", "learn", "learning", "elearning", "uni", "university", "college", "schools", "school", "student", "students", "classroom", "class",
        "netacad", "knowledge", "harvard",

        // [0.19] virtualisation
        "vm", "virtual", "vcenter", "virtual", "vsphere", "vps", "vpn0", "vpn", "vpn1", "vpn2", "citrix", "proxmox",

        // [0.20] news
        "newsletter", "blogs", "devblogs", "post", "posts", "feed", "article", "newsletter", "agent", "agents", 

        // [0.21] Legal
        "legal", "privacy", "tos", "cookies", "policy", "police", "law", "rules", "licensing", "license", "gov", "goverment", "copyright", "terms", "urheber", "urheberrecht", "datenschutz",
        "bgb", "sgb", "dmca", "complaint",

        // [0.22] hosting
        "nginx", "apache", "hosting", "bluemix", "server", "server01", "server02", "server03", "server04", "server05", "serv1", "serv", "serv2", "serv3", "serv4", "serv5",
        "wordpress", "wp", "wikimedia", "godaddy", "wix", "jimdo", "deno",

        // File Ext
        "css", "js", "ts", "doc", "php", "pdf", "cpp", "c", "json", "html", "style", "svn", "svg", "jpeg", "jpg", "png",

        // [0.24] Shell-related
        "system", "computer", "console", "shell", "root", "fs", "sh", "ping",

        // NSFW SUBDOMAINS PLEASE COLLAPSE THE REGION IF YOU DON'T WANT TO SEE THEM!!
        #pragma region NSFW_SUBDOMAINS
        // [0.25] NSFW / Dating 
        "18", "love", "dating", "sex", "0-porn", "porn", "porno", "pornos", "xxx", "xx", "cupid", "iloveyou", "wedding", "marrige", "pp", "gambling", "casino", "bet", "betting",
        "drugs", "weed", "drug", "cocaine", "heroine", "milkers", "cowgirl", "cow-girl", "bedsport", "sexchat", "sex-chat", "chaturbate",
        "nightlife", "win", "getnow", "adult", "adults", "xvideo", "xxxvideo", "xxxseries", "xxx-video", "xxxmovie", "xxx-movies", "xmovies", 
        "butt", "puss", "erotic", "erotica", "erotic-clips", "eroclips", "erome", "kissing", "kiss", "redgif", "redtube", 
        "redcontent", "red-content", "whores", "whore", "fembed", "female-bed", 
        "18comic", "18comics", "18-comic", "18-comics", "adultcomics", "erwachsenen-bereich", "xbdsm", "bdsm", "boundage", "fetish", "fetishes",
        "nude", "nudes", "nudeleak", "nudeleaks", "nude-leak", "1xxx", "2xxx", "3xxx", "4xxx", "5xxx", "6xxx", "7xxx", "8xxx", "9xxx", "10xxx", "1porn", "2porn", "3porn", "4porn", "5porn", "6porn", "7porn",
        "8porn", "9porn", "10porn",

        // NSFW: Erotic Manga / Hentai
        "hentai", "nhentai", "erohentai", "hentaimanga",
        "eromanga", "ero-manga", "manhwa18", "erodoujins",

        // NSFW: Boobs
        "breasts", "boobs", "bigboobs", "perkyboobs", "tits", "tiddies",

        // NSFW: Dicks
        "penis", "dick", "dickriding", "dicks", "cock", "cocks",
        #pragma endregion

        // [0.26] Corperation
        "corp", "corperation", "corperate", "holding", "incorperated", "inc", "llc", "limmited",

        // [0.27] Developer
        "develop", "developer", "ide", "git", "software", "coding", "code", "scripting", "webdev", "oss", "developers", "xyz", "api0", "api", "api1", "api2", "apis", "api-dev", 
        "docs", "flags", "flag", "opensource", "oss", "open-source", "computing", "master", "tools", "dev-buisness", "sso", "seo",

        // [0.28] Gender
        "male", "female", "man", "woman", "men", "boy", "girl", "boys", "girls", "mother", "father", "mom", "dad",

        // [0.29] Support
        "helpdesk", "support", "bugs", "issues", "issue", "report", "forum", "asks", "ask", "asked", "ticket", "manual", "gethelp", "infocenter", "service-desk", "servicedesk",

        // [0.30] Music Entertainment
        "music", "radio", "listen", "listening", "songs", "song", "sound", "sounds", "lyrics", "fm", "vh", "vhs", "shuffle", "stage", "instruments", "soundtrack", "soundtracks",

        // [0.31] Graphical Entertaiment
        "movie", "movies", "entertain", "entertainment", "filming", "recording", "film", "anime", "animations", "animation", "vfx", "sfx", "cgi", "watch",
        "studio", "studios", "tube", "vod", "cam", "cams", "camera", "webcams", "pictures", "cinema", "videos", "trailers", "trailer",
        "films", "productions", "production", "television", "tvgo", "tvhd", "premere", "blockbuster", "primetime", "picture", "player", "stock", "fotos", "digital", "thumb", "sports",
        "esports", "e-sports", "dvd", "analog", "hdvideos", "hdvideo", "hd-video", "hd-videos", "hdmovie", "hdmovies", "hd-movie", "hd-movies",

        // Piracy
        "piracy", "pirat", "priate", "piratebay", "pirate-bay", "kinovod0", "kinovod", "kinovod1", "animevod", "lostfilms", "lordfilms", "torret",

        // Film 0 - 10
        "film0", "film", "film1", "film2", "film3", "film4", "film5", "film6", "film7", "film8", "film9", "film10",

        // HD 0 - 10
        "hd0", "hd", "hd1", "hd2", "hd3", "hd4", "hd5", "hd6", "hd7", "hd8", "hd9", "hd10",

        // [0.32] LINUX
        "kali", "ubuntu", "darwin", "arch", "deb", "debian", "superuser", "linux", "gnu", "apt", "ls", "cd", "dpkg", "mkdir", "rm", "mv", "rmdir", "sudo", "su", "ps", "process", "processes",
        "touch", "nano", "vi", "vim", "neovim", "neofetch", "systemctl", "cp", "wget", "pkill", "kill", "net-tools", "ifconfig", "gcc",

        // [0.33] Regions
        "union", "euro", "europe", "america", "asia", "africa", "australia", "nation", "east", "west", "south", "north", "center", "central", "us-east", "us-west", "us-sorth", "us-north",
        "eu-sorth", "eu-north", "eu-west", "eu-east", "united", "latin", "earth", "moon", "sun", "us-east-1", "us-east-2", "us-north-1", "us-north-2", "us-west-1", "us-west-2", 
        "us-sorth-1", "us-sorth-2", "eu-west-1", "eu-west-2", "eu-east-1", "eu-east-2", "eu-sorth-1", "eu-sorth-2", "eu-north-1", "eu-north-2",

        // [0.34] Network Related
        "imap", "eth", "ethernet", "loopback", "nat", "nas", "client", "clients", "iot", "nmap", "network", "networks", "internet", "url", "hotspot",
        "gatekeeper", "remote", "router", "pfsense", "reciever",

        // [0.35] Account Managment
        "upload", "profile", "register", "members", "signup", "login", "dashboard", "guest", "accounts", "account", "moderation", "myaccount",

        // [0.36] Health
        "health", "heatlthy", "together", "trust", "trusting", "trusted", "safety", "safe", "care", "friends", "bio", "connect", "insurance", "meds", "medical", "hospital", "ambulance",

        // [0.37] Information
        "information", "info", "newsroom", "guide", "infopoint",

        // [0.38] Plattforms
        "mobile", "phones", "desktop", "unix", "mac", "iphone", "android", "phone", "browser", "app", "apps", "application", "applications",

        // [0.39] Security
        "oauth", "auth", "oauth2", "spy", "spying", "cyber", "cybersecurity", "hacking", "hack", "hacked", "secure", "gateway", "midway-gateway", "proxy0", "proxy", "proxy1", "proxies", "proxy-ratelimmit", "security",
        "certification", "certifications", "certificates", "certificated", "cert", "firewall", "tracking", "captcha", "hacker", "gate", "ctf0", "ctf", "ctf1", "ctf2", "ctf3", "ctf4",
        "sync", "protect", "protection", "void", "voided", "backup", "monitor", "monitoring", "ransomware", "spyware", "adware", "trojan", "trojanhorse", "trojan-horse", "malware",

        // [0.40] Game Entertainment
        "games", "gaming", "play", "arcade", "chess",

        // [0.41] Exclusive
        "pro", "premium", "subscribe", "vip", "mvp", "exclusive", "prime", "unsubscribe", "deluxe", "special", "specials", "expensive", "membership", "memberships", "pass", "noble",
        "nobles", "osscars", "club", 

        // [0.42] Words for Intern
        "localhost", "intern", "intranet", "hidden", "private",

        // [0.43] Site
        "sitemap", "site", "sites", "pages", "page", "paper", "papers",

        // [0.44] Book Entertainment
        "manga", "mangas", "books", "book", "ebook", "ebooks", "art", "artist", "artwork", "reader", "mangareader", "manga-read", "manhwa", "manhwas", "doujin", "doujins"

        // [0.45] HTTPS / PORTS
        "get", "404", "403", "0", "124", "16", "64", "8080", "80",

        // DUMMYS
        "test", "test1", "test2", "123", "1234", "abc", "abcd", "abcde", "gay", "dumb", "idiot", "secret", "dummy", "dummy1", "spam0", "spam", "spam1", "spam2",

        // Family
        "family", "child", "kids", "children",

        // Configuration
        "manager", "settings", "config", "manage", "managment", "my", "controller", "control",

        // Finance
        "finance", "wallet", "bank", "card", "crypto",

        // Version
        "beta", "alpha", "classic", "ver", "version", "old", "new", "nightly", "stable", "unstable", "insiders",

        // Document based
        "copy", "paste", "cut", "office", "edit", "editing", "view", "share",

        // QR / QRCODE
        "qr", "qrcode", "qr-code", "qrscan", "qr-scan",

        // Cores
        "home", "base", "start", "portal", "core", "kernel", "hub", 

        // Company
        "company", "staff", "employee", "press", "inpress", "invoices", "tech", "technology", "publishing", "publisher", "inventions", "investors", "projects",
        "enterprise", "buisness", "vision", "catalogue", "discover", "discovery", "service", "credit", "origin", "stocks", "history", "creative", "structure", "mission", "workplace",
        "workplaces", "workdesk", "readme",

        // Maps & GPS
        "navigation", "navi", "gps", "maps", "map", "places",

        // Metrics
        "metrics", "stats", "status", "analytics",

        // Socials
        "social", "socials", "youtube", "twitter", "github", "gitlab", "facebook", "linkedin", "xing", "maestroden", "discord",

        // File Managment
        "files", "file", "save", "publish", "update", "create", "install", "load", "loading", "planning", "plan", "download", "dnl", "list", "lists", "open", "close",

        // Companies
        "google", "hp", "microsoft", "adobe", "ibm", "apple", "netflix", "cisco", "mgsql", "htb", "ph", "amazon", "xbox", "playstation", "valve", "steam", "ubisoft", "nasa",
        "intel", "amd", "nvidia", "meta", "mg", "siemens", "phillips", "bosch", "unity", "unity3d", "unitymedia", "nova", "bk", "kfc", "cinnabon", "nintendo", "unreal", "unreal-engine",
        "w3", "nfl", "nba", "sony", "nbc", "comcast", "wb", "sme", "wmg", "umg", "nbcuniversal", "bbc", "steampowered", "airlines", "auto", "automobility", "car", "transport",
        "entertainmasters", "mindgeek",

        // Applications
        "todo", "calender", "calculator", "board", "weather", "task", "tasks", "date", "dates", "launch", "launcher", "time", "math", "powerpoint", "excel", "access", "word",
        "chrome", "apex", "minecraft", "roblox",

        // Research
        "search", "lab", "labs", "research", "tests", "sample",

        // Internal
        "internal", "printer", "printers", "classified", "personal", "disclosed",

        // Music gernes
        "edm", "chill", "tropical", "hiphop", "trap", "bass", "house", "deephouse",

        // Places
        "event", "events", "hotel", "hotels", "vacation", "vacations", "museum",

        // Resources
        "resource", "repo", "lib", "content", "library", "data", "datacenter", "data-center",

        // Collaboration
        "collaboration", "collab", "anydesk", "teamviewer", "team-viewer", "rat",

        // AI / Mashine Learning
        "cuda", "ai", "deep", "bot", "robot", "robots", "mashine", "mashine-learning", "artificial",

        // Colors
        "red", "blue", "yellow", "green", "white", "black", "orange", "pink", "purple", "cyan", "gold", "crimson", "blurple", "darkred", "darkblue", "darkgreen", "darkyellow",

        // Names
        "torvalds", "copy05", "copy2005", "billgates", "dp", "dudeperfect", "dude-perfect",

        // Misc
        "extern", "vs", "preview", "link", "linked", "awp", "originals", "collections", 
        "local", "cats", "cat", "res", "mc", "now", "transfer", "rate", "rating", 
        "contest", "build", "this", "public", "host", "net", "online", "io", "your", "you", "box", "science", "chemie", "thanks", "ocean",
        "carrd", "sender", "direct", "directory", "fresh", "banner", "recieve", "heaven", "kitchen", "recept", "cc", "idm", 
        "lu23xx", "lu-x23", "lu32", "lu23s", "lord-u32", "lord-u37", "lord-i17", "idss", "ides", "ess", "iss", "filmy", "filmymeet", "ching",
        "ching-chong", "hellish", "hell", "yts", "ssyt", "vortex0", "vortex", "vortex1", "watson", "v8", "go", "lineup",

        // Language subdomains
        "intertional", "de", "en", "nl", "jp", "gr", "es", "au", "fr", "us", "uk", "ca", "com", "it", "es", "gg", "at", "ch", "co", "mx", "bg", "ru",
    };

    const int arrc = sizeof(subdomains) / sizeof(subdomains[0]);
    int founddomains = 0;

    clock_t begin = clock();

    printf("Following subdomains has been found for %s\n", f);

#if __unix
    for (int i = 0; i < arrc; i++) {
        char cmd[0x080];
        strcpy(cmd, "ping -c1");
        strcat(cmd, subdomains[i]);
        strcat(cmd, ".");
        strcat(cmd, f);
        strcat(cmd, " > /dev/null > 2>&1");

        if (system(cmd) == 0x00) {
            printf("%s.%s\n", subdomains[i], f);
            founddomains++;
        }
    }
#else
    for (int i = 0; i < arrc; i++) {
        char cmd[0x080];
        strcpy(cmd, "ping -n 1 ");
        strcat(cmd, subdomains[i]);
        strcat(cmd, ".");
        strcat(cmd, f);
        strcat(cmd, " > nul");

        if (system(cmd) == 0x00) {
            printf("%s.%s\n", subdomains[i], f);
            founddomains++;
        }
    }
#endif
    clock_t end = clock();
    printf("%d founded subdomains for %s [%fs]\n", founddomains, f, (double)(end - begin) / CLOCKS_PER_SEC);
}
