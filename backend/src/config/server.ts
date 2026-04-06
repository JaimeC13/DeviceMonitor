import express from "express";
import monitorRouter from "../Routers/monitorRouter";
import { MonitorService } from "../Service/monitorService";



const APP = express();
const PORT = process.env.PORT || 3000;

APP.use(express.json());
APP.use('/api', monitorRouter);


APP.listen(PORT, async () => {
    console.log("Server is running on port " + PORT);




    try {
        await (MonitorService as any).getDB(); 
       
    } catch (error) {
        
    }


});

