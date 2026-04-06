import * as sqlite3 from 'sqlite3';
import { open, Database} from 'sqlite';
import { DeviceData } from '../Schemas/SchemaDevice';


export class MonitorService {

     private static db: Database | null = null;


    //validation number one and save data to database
    private static async getDB() {
        if (!this.db) {
            this.db = await open({
                filename: './monitor.db',
                driver: sqlite3.Database
            });
        }

        //validation number two: Create the table if it doesn't exist
        await this.db.run(`CREATE TABLE IF NOT EXISTS device_data (
            id INTEGER PRIMARY KEY AUTOINCREMENT,
            deviceId TEXT NOT NULL,
            ramUsage REAL NOT NULL,
            timestamp TEXT NOT NULL
        )`);

        return this.db;
    }

     static async save(data: DeviceData) {
        const db = await this.getDB();

        const result = await db.run(
            `INSERT INTO device_data (deviceId, ramUsage, timestamp) VALUES (?, ?, ?)`,
            data.deviceId,
            data.ramUsage,
            data.timestamp
        )

        return {id: result.lastID, ...data}; //..data is the rest of the properties of the object data. 
        // SQLLITE, Id is the new property that we are adding to the object that we are returning.


    }
    
}