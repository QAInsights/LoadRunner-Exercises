# Recording and Replay Exercises

**00. Create a new Web HTTP/HTML Script in VuGen**

<details><summary>Click here to view the hint/answer</summary>
<br/>
<p>
In VuGen, `File > New Script and Solution`. Enter as shown below then click on `Create`.

![Record](/00-Recording-Replay/assets/00.jpg)

</p>
</details><br/>

**10. Record the following business flow in VuGen**

Use the default Recording options in VuGen and record everything in **Action**.

* Launch https://blazedemo.com/ in Chrome
* Select Paris and London as departure and destination city respectively
* Click on Find Flights
* Stop the recording

<details><summary>Click here to view the hint/answer</summary>
<br/>
<p>

![Record](/00-Recording-Replay/assets/01.jpg)

</p>
</details><br/>

**20. Record the above business flow in a new script, but with comments for each step**

<details><summary>Click here to view the hint/answer</summary>
<br/>
<p>

![Record](/00-Recording-Replay/assets/02.jpg)

E.g.

```
Action()
{

	/* Blazedemo Website Launch */

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

	return 0;
}

```
</p>
</details><br/>

**30. Replay Script using the default Runtime Settings**
<details><summary>Click here to view the hint/answer</summary>
<br/>
<p>

![Replay](/00-Recording-Replay/assets/03.jpg)

</p>
</details><br/>