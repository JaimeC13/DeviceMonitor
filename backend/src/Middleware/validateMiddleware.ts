import { Request, Response, NextFunction } from "express";
import { ZodObject, ZodError } from 'zod';


export const validateRequest = (schema: ZodObject) => {
    return (req: Request, res: Response, next: NextFunction) => {
        try {
            schema.parse(req.body);
            next();}

            catch (error) {
               if (error instanceof ZodError) {
                return res.status(400).json({
                    message: "Error in validation" ,
                    details: error.issues.map(e => ({
                        campo: e.path.join('.'),
                        mensaje: e.message
                    }))
                });
            }
            return res.status(500).json({ message: "internal server error" });
        }
    }
};