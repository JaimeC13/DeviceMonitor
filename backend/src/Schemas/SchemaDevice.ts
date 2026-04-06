import { z } from 'zod';



export const SchemaDevice = z.object({
    deviceId: z.string().min(1, "El deviceId no puede estar vacío"),
    ramUsage: z.number().min(0).max(100, "La RAM no puede superar el 100%"),
    timestamp: z.string().datetime("Debe ser una fecha ISO 8601 válida")
    })

    export type DeviceData = z.infer<typeof SchemaDevice>;
