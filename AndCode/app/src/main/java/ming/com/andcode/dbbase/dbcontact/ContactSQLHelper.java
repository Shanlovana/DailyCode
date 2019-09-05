package com.hengtong.henchat.dbbase.dbcontact;

import android.content.Context;
import android.database.sqlite.SQLiteDatabase;

import com.hengtong.henchat.dbbase.BasicSQLHelper;


public class ContactSQLHelper extends BasicSQLHelper {

    private static final String DB_HISTORY_NAME = "contact_history.db";
    private static final int DB_HISTORY_VERSION = 1;

    static final String TABLE_NAME = "contact_his_table";
    static final String DIALERID = "dialer_id";
    static final String DIALERNAME = "dialer_name";
    static final String DIALERHEADURL = "dialer_head_url";
    static final String USERID = "user_id";
    static final String USERNAME = "user_name";
    static final String STARTTIME = "start_time";
    static final String DURATION = "duration";
    static final String CONSUMEDKEY = "consumed_key";
    static final String DAILORCALL = "daile_or_call";
    static final String VERSION = "version";

    /*create or delete tables*/


    private static final String SQL_CREATE_TABLE = "CREATE TABLE contact_his_table(_id INTEGER PRIMARY KEY AUTOINCREMENT," +
            " dialer_id TEXT, dialer_name TEXT, dialer_head_url TEXT, user_id TEXT, user_name TEXT, start_time LONG, duration LONG, consumed_key " +
            "LONG, daile_or_call TEXT, version INTEGER)";
    private static final String SQL_CREATE_UNIQUE_INDEX = "CREATE UNIQUE INDEX contact_unique_index ON contact_his_table" +
            "(\"dialer_id\", \"start_time\")";
    private static final String SQL_DELETE_TABLE = "DROP TABLE  IF EXISTS contact_his_table";

    public ContactSQLHelper(Context context) {
        super(context, DB_HISTORY_NAME, null, DB_HISTORY_VERSION);
    }

    @Override
    public void onCreate(SQLiteDatabase db) {
        db.beginTransaction();
        try {
            db.execSQL(SQL_CREATE_TABLE);
            db.execSQL(SQL_CREATE_UNIQUE_INDEX);
            db.setTransactionSuccessful();
        } finally {
            db.endTransaction();
        }
    }

    @Override
    public void onUpgrade(SQLiteDatabase db, int oldVersion, int newVersion) {
        if (newVersion != oldVersion) {
            db.beginTransaction();
            try {
                db.execSQL(SQL_DELETE_TABLE);
                db.execSQL(SQL_CREATE_TABLE);
                db.execSQL(SQL_CREATE_UNIQUE_INDEX);
                db.setTransactionSuccessful();
            } finally {
                db.endTransaction();
            }
        }
    }

    public void onDowngrade(SQLiteDatabase db, int oldVersion, int newVersion) {
        onUpgrade(db, oldVersion, newVersion);
    }
}
