Blazedemo()
{

	web_set_sockets_option("SSL_VERSION", "AUTO");

	web_add_auto_header("Accept", 
		"text/html,application/xhtml+xml,application/xml;q=0.9,image/webp,image/apng,*/*;q=0.8,application/signed-exchange;v=b3;q=0.9");

	web_add_auto_header("Sec-Fetch-Site", 
		"none");

	web_add_auto_header("Sec-Fetch-Mode", 
		"navigate");

	web_add_auto_header("Sec-Fetch-Dest", 
		"document");

	web_add_auto_header("Accept-Encoding", 
		"gzip, deflate, br");

	web_add_auto_header("Accept-Language", 
		"en-US,en;q=0.9,ta;q=0.8");

	web_add_auto_header("DNT", 
		"1");

	web_add_auto_header("Sec-Fetch-User", 
		"?1");

	web_add_auto_header("Upgrade-Insecure-Requests", 
		"1");

	web_url("blazedemo.com", 
		"URL=https://blazedemo.com/", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t1.inf", 
		"Mode=HTML", 
		LAST);

	lr_start_transaction("T10_FindFlights");

	web_add_auto_header("Cache-Control", 
		"max-age=0");

	web_add_auto_header("Origin", 
		"https://blazedemo.com");

	web_add_auto_header("Sec-Fetch-Site", 
		"same-origin");

	web_submit_form("reserve.php", 
		"Snapshot=t2.inf", 
		ITEMDATA, 
		"Name=fromPort", "Value=Paris", ENDITEM, 
		"Name=toPort", "Value=Buenos Aires", ENDITEM, 
		LAST);

	lr_think_time(16);

	lr_start_transaction("T20_ChooseThisFlight");

	web_submit_form("purchase.php", 
		"Ordinal=1", 
		"Snapshot=t3.inf", 
		ITEMDATA, 
		LAST);

	lr_end_transaction("T20_ChooseThisFlight",LR_AUTO);

	lr_end_transaction("T10_FindFlights",LR_AUTO);

	lr_think_time(41);

	lr_start_transaction("T30_BookFlight");

	web_submit_form("confirmation.php", 
		"Snapshot=t4.inf", 
		ITEMDATA, 
		"Name=inputName", "Value=John", ENDITEM, 
		"Name=address", "Value=123 Main Rd", ENDITEM, 
		"Name=city", "Value=DemoCity", ENDITEM, 
		"Name=state", "Value=Imagineering", ENDITEM, 
		"Name=zipCode", "Value=11111", ENDITEM, 
		"Name=cardType", "Value=Visa", ENDITEM, 
		"Name=creditCardNumber", "Value=9876543214567891", ENDITEM, 
		"Name=creditCardMonth", "Value=12", ENDITEM, 
		"Name=creditCardYear", "Value=2020", ENDITEM, 
		"Name=nameOnCard", "Value=", ENDITEM, 
		"Name=rememberMe", "Value=<OFF>", ENDITEM, 
		LAST);

	lr_end_transaction("T30_BookFlight",LR_AUTO);

	return 0;
}