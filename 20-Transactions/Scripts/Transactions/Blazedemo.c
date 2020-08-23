Blazedemo()
{

	web_set_sockets_option("SSL_VERSION", "AUTO");

	lr_start_transaction("T00_Launch");
	
		web_url("blazedemo.com", 
			"URL=https://blazedemo.com/", 
			"Resource=0", 
			"RecContentType=text/html", 
			"Referer=", 
			"Snapshot=t1.inf", 
			"Mode=HTML", 
			LAST);
	
	lr_end_transaction("T00_Launch", LR_AUTO);

	lr_start_transaction("T10_FindFlights");

		web_submit_form("reserve.php", 
			"Snapshot=t2.inf", 
			ITEMDATA, 
			"Name=fromPort", "Value=Paris", ENDITEM, 
			"Name=toPort", "Value=Buenos Aires", ENDITEM, 
			LAST);

	lr_end_transaction("T10_FindFlights",LR_AUTO);

	lr_start_transaction("T20_ChooseThisFlight");

		web_submit_form("purchase.php", 
			"Ordinal=1", 
			"Snapshot=t3.inf", 
			ITEMDATA, 
			LAST);

	lr_end_transaction("T20_ChooseThisFlight",LR_AUTO);

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