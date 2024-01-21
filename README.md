<h1>Car Sharing GPS tracking system project</h1>

<p>This is the project to make a gps system for car sharing, that catches the car position by gps module and sends it via sms to dedicated phon number each 2 minutes. One of aim of this project was to make the system as much energy efficient as possible.</p>

<h2><b>Project targets</b></h2> 

<p>The first stage was to define the project targets. Those are:</p>
<ul>
  <li>Small tracking device</li>
  <li>Lasting for a long time</li>
  <li>Adapted to railway conditions</li>
  <li>Sends location and status to user</li>
  <li>Cheaper than 500 PLN</li>
</ul>

<p>Existing solutions:</p>
<table>
  <tr>
    <th><img src="images/device1.png" alt="Alt Text" width="200"/></th>
    <th><img src="images/device2.png" alt="Alt Text" width="200"/></th>
    <th><img src="images/device3.png" alt="Alt Text" width="200"/></th>
  </tr>
  <tr>
    <td>Has phone app</td>
    <td>Has phone app</td>
    <td>Has phone app</td>
  </tr>
  <tr>
    <td>3V 3000mAh</td>
    <td>4800mAh 550 days of work, if 1 report per day</td>
    <td>550 days of work, if 24 reports per day</td>
  </tr>
  <tr>
    <td>Uses SigFox network</td>
    <td>Uses Satellite for connection</td>
    <td>Uses Satellite for connection</td>
  </tr>
  <tr>
    <td><a href="https://partners.sigfox.com/products/chipfox-gps-tracker-heavy-duty">LINK</a></td>
    <td><a href="https://www.rewiresecurity.co.uk/sat50-satellite-asset-tracker">LINK</a></td>
    <td><a href="https://aliresources.hexagon.com/fabrication/geoforce-gt0-industrial-grade-gps-asset-tracker">LINK</a></td>
  </tr>
</table>


<h2><b>Project electronics</b></h2> 
<table>
  <tr>
    <th>Module</th>
    <th>Name</th>
    <th>Picture</th>
    <th>Power consumption</th>
    <th>Cost</th>
  </tr>
  <tr>
    <td>GSM</td>
    <td>SIM800L</td>
    <td>pic</td>
    <td>GSM transmission (average): 350 mA, 1.75W</td>
    <td>38,86 PLN</td>
  </tr>
  <tr>
    <td>GPS</td>
    <td>NEO6MV2</td>
    <td>pic</td>
    <td>67 mA, 0,335 W</td>
    <td>30 pln</td>
  </tr>
  <tr>
    <td>Microcontroller</td>
    <td>Arduino UNO</td>
    <td>pic</td>
    <td>250mW in regular mode, 1mW in powerdown sleep mode</td>
    <td>80 pln</td>
  </tr>
  <tr>
    <td>Battery</td>
    <td>18650</td>
    <td>pic</td>
    <td>-</td>
    <td>12 pln</td>
  </tr>
  <tr>
    <td>BMS</td>
    <td>BMS 2S1P</td>
    <td>pic</td>
    <td>-</td>
    <td>8 pln</td>
  </tr>
  <tr>
    <td>Power converter</td>
    <td>LM2596</td>
    <td>pic</td>
    <td>typically 10% from total power consumption</td>
    <td>10 pln</td>
  </tr>
</table>
<img src="images/circuitry.png" alt="Alt Text" width="300"/>
