import { Router } from "express";
import { HealthController } from "../Controllers/monitorController";
import { validateRequest } from "../Middleware/validateMiddleware";
import { SchemaDevice } from "../Schemas/SchemaDevice";

export const router = Router();

router.post("/monitor", validateRequest(SchemaDevice), HealthController.create);

export default router;

