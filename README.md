# raytracer

A multithreaded raytracer.

### Example output:

![Example Output 1](https://raw.githubusercontent.com/mylez/raytracer/main/image-output/rgb-teapot-multiple-lights-10spp.png)

![Example Output 2](https://raw.githubusercontent.com/mylez/raytracer/main/image-output/manyspheres-50samples.png)
![Example Output 3](https://raw.githubusercontent.com/mylez/raytracer/main/image-output/multibulb.png)
![Example Output 4](https://raw.githubusercontent.com/mylez/raytracer/main/image-output/shadow-3-light.png)

### And finally, something cool you can do is render scenes as text.

    |================================================================|
    |================================================================|
    |================================================================|
    |================================================================|
    |================================================================|
    |================================================================|
    |================================================================|
    |==================================== . . . . . . .==============|
    |================================== . . . . . . . . . . . . . .==|
    |============================== . . . . . . . . . . . . . . . . .|
    |============================ . . . . . . . . . . . . . . . . . .|
    |========================== . . . . . . . . . . . . . . . . . . .|
    |======================== . . . . . . . . . . . . . . . . . . . .|
    |======================== . . . . . . . . . . . . . . . . . . . .|
    |======================== . . . . . . . . . . . . . . . . . . . .|
    |==================== . . . . . . . . . . . . . . . . . . . . . .|
    |================ . . . . . . . . . . . . . . . . . . . . . . .==|
    |============== . . .== . .== . . . . . . . . . . . . . . .======|
    |============== . .==== . .==== . . . . . . . . . . . . .========|
    |============== .==== . . .========== . . . . . . . . .==========|
    |==================== . .============ . . . . . .================|
    |================================================================|
    |================================================================|
    |================================================================|
    |================================================================|
    |================================================================|
    |================================================================|
    |================================================================|
    |================================================================|
    |================================================================|
    |================================================================|
    |================================================================|
    |================================================================|
    |================================================================|
    |================================================================|
    |================================================================|
    |================================================================|
    |================================================================|
    |================================================================|
    |======================================== . . .==================|
    |==================================== . . . . . . . . .==========|
    |============================ . .== . . . . . . . . . . .========|
    |======================== . . . . . . . . . . . . . . . . . .====|
    |======================== . . . . . . . . . . . . . . . . . .====|
    |======================== . . . . . . . . . . . . . . . . . . .==|
    |======================== . . . . . . . . . . . . . . . . . . . .|
    |==================== . . . . . . . . . . . . . . . . . . . . . .|
    |================== . . . . . . . . . . . . . . . . . . . . . . .|
    |================ . . . . . . . . . . . . . . . . . . . . . . . .|
    |============== . . .== . . . . . . . . . . . . . . . . . . . . .|
    |============== . .== . .==== . . . . . . . . . . . . . . . . . .|
    |==================== .======== . . . . . . . . . . . . . . . . .|
    |================================== . . . . . . . . . . . . . . .|
    |====================================== . . . . . .====== . .====|
    |================================================================|
    |================================================================|
    |================================================================|
    |================================================================|
    |================================================================|
    |================================================================|
    |================================================================|
    |================================================================|
    |================================================================|
    |================================================================|
    |================================================================|
    |================================================================|
    |================================================================|
    |================================================================|
    |================================================================|
    |================================================================|
    |================================================================|
    |========================== . .==================================|
    |======================== . . . .====== . . . . . .== . .========|
    |======================== . . . . . . . . . . . . . . . .========|
    |====================== . . . . . . . . . . . . . . . . . .======|
    |====================== . . . . . . . . . . . . . . . . . . .====|
    |====================== . . . . . . . . . . . . . . . . . . . .==|
    |==================== . . . . . . . . . . . . . . . . . . . . .==|
    |================== . . . . . . . . . . . . . . . . . . . . . .==|
    |================ . . . . . . . . . . . . . . . . . . . . . . .==|
    |================ . .== . . . . . . . . . . . . . . . . . . . .==|
    |============== . . .== .== . . . . . . . . . . . . . . . . . . .|
    |================ .======== . . . . . . . . . . . . . . . . . . .|
    |============================ . . . . . . . . . . . . . . . . . .|
    |============================ . . . . . . . . . . . . . . . . . .|
    |============================== . . . . . . . . . . . . . . . . .|
    |================================== . . . . . . . . . . . . . . .|
    |================================================== . . . . . . .|
    |================================================== . . . . . .==|
    |==================================================== . . . .====|
    |================================================================|
    |================================================================|
    |================================================================|
    |================================================================|
    |================================================================|
    |================================================================|
    |================================================================|
    |================================================================|
    |================================================================|
    |================================================================|
    |================================================================|
    |========================== . .==================================|
    |======================== . . . .================================|
    |====================== . . . . .== . . .========================|
    |====================== . . . . . . . . . .====== . . .==========|
    |====================== . . . . . . . . . . . . . . . . . .======|
    |====================== . . . . . . . . . . . . . . . . . . .====|
    |====================== . . . . . . . . . . . . . . . . . . .====|
    |==================== . . . . . . . . . . . . . . . . . . . .====|
    |================== . . . .== . . . . . . . . . . . . . . . . .==|
    |================== . . . . . . . . . . . . . . . . . . . . . .==|
    |================ . . . .== . . . . . . . . . . . . . . . . . . .|
    |================ . .====== . . . . . . . . . . . . . . . . . . .|
    |================ . .====== . . . . . . . . . . . . . . . . . .==|
    |========================== . . . . . . . . . . . . . . . . . .==|
    |========================== . . . . . . . . . . . . . . . . .====|
    |============================ . . . . . . . . . . . . . . . .====|
    |============================ . . . . . . . . . . . . . . . . .==|
    |============================== . . . . . . . . . . . . . . . .==|
    |================================== . . . . . . . . . . . . . .==|
    |======================================== . . . . . . . . . . .==|
    |============================================== . . . . . . .====|
    |================================================ . . . . . .====|
    |================================================ . . . . .======|
    |================================================================|
    |================================================================|
    |================================================================|
    |================================================================|
    |================================================================|
    |================================================================|
    |================================================================|
    |======================== . . .==================================|
    |====================== . . . . .================================|
    |==================== . . . . . .================================|
    |==================== . . . . . . . . . . .======================|
    |==================== . . . . . . . . . . . .======== . .========|
    |==================== . . . . . . . . . . . .====== . . . .======|
    |==================== . . . . . . . . . . . . .==== . . .========|
    |==================== . . . . . . . . . . . . . . . . . . . .====|
    |==================== . . . . . . . . . . . . . . . . . . . . .==|
    |================== . . . .== . . . . . . . . . . . . . . . . .==|
    |================== . . .==== . . . . . . . . . . . . . . . . .==|
    |================ . . .====== . . . . . . . . . . . . . . . . .==|
    |================ . . .==== . . . . . . . . . . . . . . . . . .==|
    |================ . .====== . . . . . . . . . . . . . . . . . .==|
    |================== .====== . . . . . . . . . . . . . . . . . .==|
    |========================== . . . . . . . . . . . . . . . . . .==|
    |========================== . . . . . . . . . . . . . . . . . .==|
    |========================== . . . . . . . . . . . . . . . . . .==|
    |============================ . . . . . . . . . . . . . . . .====|
    |============================== . . . . . . . . . . . . . .======|
    |================================ . . . . . . . . . . . . .======|
    |================================== . . . . . . . . . . . .======|
    |============================================ . . . . . .========|
    |============================================ . . . . . .========|
    |============================================== . . . .==========|
    |================================================================|
    |================================================================|
    |================================================================|
    |================================================================|
    |================================================================|
    |================================================================|
    |====================== . . . .==================================|
    |==================== . . . . . .================================|
    |================== . . . . . . .================================|
    |================== . . . . . . .== . . . .======================|
    |================== . . . . . . . . . . . . .====================|
    |================== . . . . . . . . . . . . . .========== . .====|
    |================== . . . . . . . . . . . . . .======== . . .====|
    |================== . . . . . . . . . . . . . . . . . . . . .====|
    |==================== . . . . . . . . . . . . . . . . . . . .====|
    |================== . . . . . . . . . . . . . . . . . . . . .====|
    |================== . .==== . . . . . . . . . . . . . . . . . .==|
    |================ . . .====== . . . . . . . . . . . . . . . . . .|
    |================ . . .====== . . . . . . . . . . . . . . . . . .|
    |================ . .======== . . . . . . . . . . . . . . . . . .|
    |================ . .====== . . . . . . . . . . . . . . . . . .==|
    |========================== . . . . . . . . . . . . . . . . . .==|
    |========================== . . . . . . . . . . . . . . . . . .==|
    |========================== . . . . . . . . . . . . . . . . .====|
    |========================== . . . . . . . . . . . . . . . . .====|
    |============================ . . . . . . . . . . . . . . . .====|
    |============================ . . . . . . . . . . . . . . . .====|
    |============================== . . . . . . . . . . . . .========|
    |================================ . . . . . . . . . . .==========|
    |======================================== . . . . . .============|
    |========================================== . . . . .============|
    |================================================================|
    |================================================================|
    |================================================================|
    |================================================================|
    |================================================================|
    |================================================================|
    |================================================================|
    |====================== . . . .==================================|
    |================== . . . . . . .================================|
    |================ . . . . . . . .================================|
    |============== . . . . . . . . . . . . . . .====================|
    |============== . . . . . . . . . . . . . . . .==================|
    |============== . . . . . . . . . . . . . . . . .================|
    |============== . . . . . . . . . . . . . . . . .====== .========|
    |================ . . . . . . . . . . . . . . . .== . . . . . . .|
    |================ . . . . . . . . . . . . . . . . . . . . . . . .|
    |================== . . . . . . . . . . . . . . . . . . . . . . .|
    |================ . . .== . . . . . . . . . . . . . . . . . . . .|
    |================ . . .==== . . . . . . . . . . . . . . . . . .==|
    |============== . . . .====== . . . . . . . . . . . . . . . . .==|
    |================ . .======== . . . . . . . . . . . . . . . . .==|
    |========================== . . . . . . . . . . . . . . . . . . .|
    |========================== . . . . . . . . . . . . . . . . . . .|
    |========================== . . . . . . . . . . . . . . . . . . .|
    |========================== . . . . . . . . . . . . . . . . . .==|
    |========================== . . . . . . . . . . . . . . . . .====|
    |============================ . . . . . . . . . . . . . . .======|
    |============================ . . . . . . . . . . . . . . .======|
    |============================== . . . . . . . . . . . . .========|
    |================================== . . . . . . . .==============|
    |========================================== . . .================|
    |================================================================|
    |================================================================|
    |================================================================|
    |================================================================|
    |================================================================|
    |================================================================|
    |================================================================|
    |================================================================|
    |================================================================|
    |================================================================|
    |====================== . . . .==================================|
    |============ . . . . . . . . . .==== . . .======================|
    |============ . . . . . . . . . . . . . . . . .==================|
    |============ . . . . . . . . . . . . . . . . . .================|
    |============ . . . . . . . . . . . . . . . . . .================|
    |============ . . . . . . . . . . . . . . . . . . .==== . . .====|
    |============ . . . . . . . . . . . . . . . . . . .== . . . .====|
    |============ . . . . . . . . . . . . . . . . . . . . . . . . . .|
    |============== . . . . . . . . . . . . . . . . . . . . . . . . .|
    |============== . . . . . . . . . . . . . . . . . . . . . . . . .|
    |============== . . .==== . . . . . . . . . . . . . . . . . . . .|
    |========================== . . . . . . . . . . . . . . . . . . .|
    |============================ . . . . . . . . . . . . . . . . . .|
    |========================== . . . . . . . . . . . . . . . . . .==|
    |========================== . . . . . . . . . . . . . . . . . .==|
    |========================== . . . . . . . . . . . . . . . . . .==|
    |========================== . . . . . . . . . . . . . . . . . .==|
    |============================ . . . . . . . . . . . . . . . .====|
    |============================== . . . . . . . . . . . . .========|
    |================================ . . . . . . . . . .============|
    |==================================== . . . . . .================|
    |================================================================|
    |================================================================|
    |================================================================|
    |================================================================|
    |================================================================|
    |================================================================|
    |================================================================|
    |================================================================|
    |================================================================|
    |================================================================|
    |================================================================|
    |================================================================|
    |============ .==================================================|
    |============ . . . .============================================|
    |============ . . . . . . . . .====== . . . .====================|
    |========== . . . . . . . . . . . . . . . . . . .================|
    |========== . . . . . . . . . . . . . . . . . . .================|
    |======== . . . . . . . . . . . . . . . . . . . . .====== . . .==|
    |======== . . . . . . . . . . . . . . . . . . . . . .== . . . .==|
    |======== . . . . . . . . . . . . . . . . . . . . . . . . . . .==|
    |========== . . . . . . . . . . . . . . . . . . . . . . . . . .==|
    |========== . . . . . . . . . . . . . . . . . . . . . . . . . .==|
    |========== . . . . . . . . . . . . . . . . . . . . . . . . . . .|
    |============ . . . . . . . . . . . . . . . . . . . . . . . . . .|
    |============== . . . . . . . . . . . . . . . . . . . . . . . . .|
    |================ . . . . . . . . . . . . . . . . . . . . . . . .|
    |====================== . . . . . . . . . . . . . . . . . . . . .|
    |============================ . . . . . . . . . . . . . . . .====|
    |============================ . . . . . . . . . . . . . . . .====|
    |================================ . . . . . . . . . . . . .======|
    |==================================== . . . . . . .==============|
    |====================================== . . .====================|
    |================================================================|
    |================================================================|
    |================================================================|
    |================================================================|
    |================================================================|
    |================================================================|
    |================================================================|
    |================================================================|
    |================================================================|
    |================================================================|
    |================================================================|
    |======== .======================================================|
    |======== . . . . .==============================================|
    |======== . . . . .==============================================|
    |========== . . . .==============================================|
    |========== . . . .==============================================|
    |========== . . . . .============================================|
    |============ . . . .==== .======== . . . . . .==================|
    |============ . . . . . . . . . . . . . . . . . .==== .==========|
    |============ . . . . . . . . . . . . . . . . . . . . . . . . .==|
    |========== . . . . . . . . . . . . . . . . . . . . . . . . . . .|
    |======== . . . . . . . . . . . . . . . . . . . . . . . . . . . .|
    |======== . . . . . . . . . . . . . . . . . . . . . . . . . . . .|
    |======== . . . . . . . . . . . . . . . . . . . . . . . . . . .==|
    |======== . . . . . . . . . . . . . . . . . . . . . . . . . . .==|
    |======== . . . . . . . . . . . . . . . . . . . . . . . . . . . .|
    |========== . . . . . . . . . . . . . . . . . . . . . . . . . . .|
    |========== . . . . . . . . . . . . . . . . . . . . . . . . . . .|
    |========== . . . . . . . . . . . . . . . . . . . . . . . . . . .|
    |============ . . . . . . . . . .== . . . . . . . . . . .== . . .|
    |============== . . . . . . . . .==== . . . . .====== . .========|
    |================ . . . . . . .==================================|
    |================== . . .========================================|
    |================================================================|
    |================================================================|
    |================================================================|
    |================================================================|
    |================================================================|
    |================================================================|
