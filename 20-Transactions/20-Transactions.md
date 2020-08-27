# Transactions

Business transactions to record for this exercise. For sample script, please refer [Scripts](https://github.com/QAInsights/LoadRunner-Exercises/tree/master/20-Transactions/Scripts/Transactions).

|   **Steps to record**   | **Transaction Name**  |
|   ---------------   | ----------------  |
|   Launch [https://blazedemo.com](https://blazedemo.com)   |   T00_Launch  |
|   Select desired locations, click on `Find Flights`   |   T10_FindFlights |
|   Select any `Choose this Flight` |   T20_ChooseThisFlight    |
|   Fill the form and then click on `Purchase Flight` |   T30_BookFlight  |
 

---

**00. Create above mentioned transactions while recording.**

<details><summary>Click here to view the hint/answer</summary>
<br/>
<p>
In the Recording toolbar, click on `Insert Start Transaction` before the page navigation or clicks, once the page is loaded completed, click `Insert `End Transaction`.

![Record](/20-Transactions/assets/00.jpg)

</p>
</details><br/>

**10. How to add transactions in Action?**

<details><summary>Click here to view the hint/answer</summary>
<br/>
<p>
Select the steps in the desired action, right click > `Surround with Transaction`.

![Record](/20-Transactions/assets/10.jpg)

</p>
</details><br/>

**20. How to intentioanlly fail a transaction?**

<details><summary>Click here to view the hint/answer</summary>
<br/>
<p>
In `lr_end_transaction`, add `LR_FAIL` argument as shown below.

```
	lr_start_transaction("T00_Launch");

        web_url("blazedemo.com", 
            "URL=https://blazedemo.com/", 
            "Resource=0", 
            "RecContentType=text/html", 
            "Referer=", 
            "Snapshot=t1.inf", 
            "Mode=HTML", 
            EXTRARES, 
            "Url=/favicon.ico", ENDITEM, 
            LAST);

	lr_end_transaction("T00_Launch",LR_FAIL);
```
</p>
</details><br/>

**30. How to configure Automatic Transactions settings?**

<details><summary>Click here to view the hint/answer</summary>
<br/>
<p>
Go to Runtime Settings, General > Miscellaneous > Automatic Transactions as shown below.
</p>

![Automatic Transactions](/20-Transactions/assets/30.jpg)

</details><br/>

**40. How to create a transaction, its status, and its duration in a single call?**

<details><summary>Click here to view the hint/answer</summary>
<br/>
<p>
Use lr_set_transaction() function as shown below.

```
 lr_set_transaction("T00_Blazedemo", 5, LR_PASS);
		
    web_url("blazedemo.com", 
		"URL=https://blazedemo.com/", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t1.inf", 
		"Mode=HTML", 
		EXTRARES, 
		"Url=/favicon.ico", ENDITEM, 
		LAST);

  lr_set_transaction("T00_Example", 1, LR_PASS);
  
	web_url("blazedemo.com", 
		"URL=https://example.com/", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t1.inf", 
		"Mode=HTML", 
		EXTRARES, 
		"Url=/favicon.ico", ENDITEM, 
		LAST);

```
</p>

</details><br/>

**50. How to create sub transactions?**
<details><summary>Click here to view the hint/answer</summary>
<br/>
<p>
By using lr_start_sub_transaction() and lr_end_sub_transaction() functions inside the transactions. E.g.

```
lr_start_transaction("BookFlight");

	lr_start_sub_transaction("BookFlight","SearchFlight");
		...
		...
	lr_end_sub_transaction("SearchFlight", LR_AUTO);

lr_end_sub_transaction("BookFlight", LR_AUTO);

```
</p>
</details>