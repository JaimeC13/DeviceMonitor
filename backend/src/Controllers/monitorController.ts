import { Request, Response  } from "express";
import type { SchemaDevice, DeviceData  } from "../Schemas/SchemaDevice";
import { MonitorService  } from "../Service/monitorService";


export class HealthController {

    static async create(req: Request, res: Response) {
        try {
            const data : DeviceData  = req.body;
            const result = await MonitorService.save(data);

            return res.status(201).json(result);

        }
        catch (error) {

            console.error("Error saving device data:", error);
            return res.status(500).json({ message: "Internal server error" });
        }
    }


}