#ifndef forms_h
#define forms_h

const char frmConnect[] = "<html>"
"<head>"
"<meta name = \"viewport\" content = \"width = device-width, initial-scale = 1.0, maximum-scale = 1.0, user-scalable=0\">"
"<title>Mind Control Device</title>"
"<style>"
"body{color:#fff;padding:10px; background:#333;}"
"label{width:40px;}"
".btn{width:80%;margin:6px;0px}"
"</style>"
"</head>"
"<body>"
"<h1>Mind Control Device</h1>"
"<h2>Connect to WIFI network</h2>"
"<form method=\"post\" action=\"/\">"
"<label>SSID:</label><input type=\"text\" name=\"ssid\"/><br/>"
"<label>Pass:</label><input type=\"password\" name=\"pass\"/><br/>"
"<input class=\"btn\" id=\"btnSubmit\" type=\"submit\" value=\"submit\"/>"
"</form>"
"</body>"
"</html>";

#endif
