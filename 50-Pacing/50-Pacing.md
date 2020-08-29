# Pacing

> Pacing enables you to control the time between iterations. The pace tells the Vuser how long to wait between iterations of your actions.

**00. Where to configure Pacing setting?**
<details><summary>Click here to view the hint/answer</summary>
<br/>
<p>
Go to Replay > Runtime Settings > General > Pacing.
</p>

![Pacing](./assets/00.jpg)

</details><br/>

**10. Which option you will select to configure the iteration at predefined fixed/random interval?**
<details><summary>Click here to view the hint/answer</summary>
<br/>
<p>
</p>

![Pacing](./assets/10.jpg)

</details><br/>

**20. Which option you will select to configure the random pacing after the previous iteration ends?**
<details><summary>Click here to view the hint/answer</summary>
<br/>
<p>
</p>

![Pacing](./assets/20.jpg)

</details><br/>

**30. How to edit pacing settings from the config file?**
<details><summary>Click here to view the hint/answer</summary>
<br/>
<p>
Go to the desired script folder, open `default.usp` file and edit the settings under `[RunLogicRunRoot]`.
</p>
</details><br/>

**40. How to change the pacing type in default.usp?**
<details><summary>Click here to view the hint/answer</summary>
<br/>
<p>
Go to the desired script folder, open `default.usp` file and edit the pacing type under `[RunLogicPaceType]`.
</p>
<pre>
|   RunLogicPaceType    |
|   ----------------    |
|   ASAP                |
|   Const               |
|   Random              |
|   ConstAfter          |
|   After               |
</pre>
</details><br/>

