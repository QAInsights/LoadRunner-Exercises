# Manual Correlation

There are multiple ways to manually correlate dynamic values. You can follow your convenient method to correlate for below exercices.  
Please record the Pet Store business transactions mentioned in [this exercise](https://github.com/QAInsights/LoadRunner-Exercises/blob/master/90-AutoCorrelation/90-AutoCorrelation.md).

**00. How to manually correlate `jsessionid` in Pet Store script?**
<details><summary>Click here to view the hint/answer</summary>
<br/>
<p>

- Copy the session ID
- Press `Ctrl + F`, check `Code Edition`, `Snapshots`, and `Logs` and then click on `Find All`  
- In the `Search Results`, look for Record, Response, Body, Text for the session ID.
- Double click on it, this will highlight in which request the session ID got generated and it will take you to `Snapshot` view.
- In the `Snapshot` view, copy the complete line with left and right boundary. E.g. `<div id="LogoContent"><a href="/actions/Catalog.action;jsessionid=CBCFF70F80422770F259736286C5E287"><img src="../images/logo-topbar.gif" /></a></div>`
- From the above string, derive the left and right boundary which will uniquely identify the session ID. E.g. `;jsessionid=CBCFF70F80422770F259736286C5E287">`
- Add the below function just before the session ID appears in the script.

```
	web_reg_save_param_ex(
		"ParamName=C_SessionID",
		"LB=jsessionid",
		"RB=\"",
		"Ordinal=1",
		SEARCH_FILTERS,
		LAST);

```
- Replace the session ID with `{C_SessionID}`

</p>

</details><br/> 

**10. How to correlate `jsessionid` using semi-auto method?**
<details><summary>Click here to view the hint/answer</summary>
<br/>
<p>

- Copy the session ID
- Press `Ctrl + F`, check `Code Edition`, `Snapshots`, and `Logs` and then click on `Find All`  
- In the `Search Results`, look for Record, Response, Body, Text for the session ID.
- This wil highlight the session ID in the `Snapshot` view.
- Right click on the value, click on `Create Correlation`
- This will open `Design Studio`, click on `Correlate` button which will correlate and replace all the session IDs in the script.

</p>

</details><br/> 

**10. Print the recent Order ID in the Output log.**
<details><summary>Click here to view the hint/answer</summary>
<br/>
<p>

```
web_reg_save_param_ex(
		"ParamName=C_OrderID",
		"LB=Order #",
		"RB=\n",
		SEARCH_FILTERS,
		"Scope=Body",
		LAST);


	web_url("Confirm", 
		"URL=https://petstore.octoperf.com/actions/Order.action?newOrder=&confirmed=true", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://petstore.octoperf.com/actions/Order.action", 
		"Snapshot=t23.inf", 
		"Mode=HTML", 
		LAST);

	lr_log_message(lr_eval_string("{C_OrderID}"));

```
</p>

</details><br/>

**10. Print the last Fish Product ID in the Output log.**
<details><summary>Click here to view the hint/answer</summary>
<br/>
<p>

```
char lastValue[30];
//...
//...
lr_start_transaction("T30_Fish");
	
	web_reg_save_param_regexp(
		"ParamName=C_ProductID",
		"RegExp=productId=(.+?)\">(.+?)</a></td>",
		"Group=1",
		"Ordinal=ALL",
		SEARCH_FILTERS,
		LAST);
	
	web_url("sm_fish.gif", 
		"URL=https://petstore.octoperf.com/actions/Catalog.action?viewCategory=&categoryId=FISH", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://petstore.octoperf.com/actions/Catalog.action", 
		"Snapshot=t18.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("T30_Fish",LR_AUTO);
	
	//Get the count of Fish Product and store the count along with the C_ProductID
	sprintf(lastValue, "{C_ProductID_%s}", lr_eval_string("{C_ProductID_count}"));
	
	//Save the last product ID to the fishProduct
 	lr_save_string( lr_eval_string(lastValue) ,"fishProduct");
	
 	//Print the fish product
 	lr_log_message("last value is %s", lr_eval_string("{fishProduct}"));

```
</p>

</details><br/>

