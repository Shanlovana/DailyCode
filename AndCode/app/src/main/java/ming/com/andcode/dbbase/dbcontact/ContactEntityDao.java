package com.hengtong.henchat.dbbase.dbcontact;

import android.content.ContentValues;
import android.content.Context;
import android.database.Cursor;
import android.database.sqlite.SQLiteDatabase;



import com.hengtong.henchat.dbbase.BaseDao;


import java.util.ArrayList;
import java.util.List;

public class ContactEntityDao extends BaseDao<ContactEntity> {

    public ContactEntityDao(Context context) {
        super(new ContactSQLHelper(context));
    }
    @Override
    public List<ContactEntity> getList(String querySql) {
        SQLiteDatabase database = getReader();
        List<ContactEntity> contacts = new ArrayList<>();
        Cursor cursor = database.rawQuery(querySql, null);
        while (!cursor.isClosed() && cursor.moveToNext()) {
            ContactEntity entity = new ContactEntity();
            entity.setId(cursor.getInt(cursor.getColumnIndex(ContactSQLHelper.ID)));
            entity.setDialer_id(cursor.getString(cursor.getColumnIndex(ContactSQLHelper.DIALERID)));
            entity.setDialer_name(cursor.getString(cursor.getColumnIndex(ContactSQLHelper.DIALERNAME)));
            entity.setDialer_head_url(cursor.getString(cursor.getColumnIndex(ContactSQLHelper.DIALERHEADURL)));
            entity.setUser_id(cursor.getString(cursor.getColumnIndex(ContactSQLHelper.USERID)));
            entity.setUser_name(cursor.getString(cursor.getColumnIndex(ContactSQLHelper.USERNAME)));
            entity.setStart_time(cursor.getLong(cursor.getColumnIndex(ContactSQLHelper.STARTTIME)));
            entity.setDuration(cursor.getLong(cursor.getColumnIndex(ContactSQLHelper.DURATION)));
            entity.setConsumed_key(cursor.getLong(cursor.getColumnIndex(ContactSQLHelper.CONSUMEDKEY)));
            entity.setDaile_or_call("true".equals(cursor.getString(cursor.getColumnIndex(ContactSQLHelper.DAILORCALL))));
            entity.setVersion(cursor.getInt(cursor.getColumnIndex(ContactSQLHelper.VERSION)));
            contacts.add(entity);
        }
        closeCursor(cursor);
        closeDateBase(database);
        return contacts;
    }
    @Override
    public long replace(ContactEntity contactEntity) {
        SQLiteDatabase database = getWriter();
        database.beginTransaction();
        ContentValues values = new ContentValues();
        values.put(ContactSQLHelper.DIALERID, contactEntity.getDialer_id());
        values.put(ContactSQLHelper.DIALERNAME, contactEntity.getDialer_name());
        values.put(ContactSQLHelper.DIALERHEADURL, contactEntity.getDialer_head_url());
        values.put(ContactSQLHelper.USERID, contactEntity.getUser_id());
        values.put(ContactSQLHelper.USERNAME, contactEntity.getUser_name());
        values.put(ContactSQLHelper.STARTTIME, contactEntity.getStart_time());
        values.put(ContactSQLHelper.DURATION, contactEntity.getDuration());
        values.put(ContactSQLHelper.CONSUMEDKEY, contactEntity.getConsumed_key());
        values.put(ContactSQLHelper.DAILORCALL, String.valueOf(contactEntity.isDaile_or_call()));
        values.put(ContactSQLHelper.VERSION, contactEntity.getVersion());
        try {
            long result = database.replace(ContactSQLHelper.TABLE_NAME, null, values);
            database.setTransactionSuccessful();
            return result;
        } catch (Exception e) {
            return -1;
        } finally {
            database.endTransaction();
            closeDateBase(database);
        }
    }

    @Override
    protected String getTableName() {
        return ContactSQLHelper.TABLE_NAME;
    }

    @Override
    protected  List<ContactEntity>  queryByAll(String querySql) {
       // List<ContactEntity> contacts=  getList(querySql);
       /* SQLiteDatabase database = getReader();
        List<ContactEntity> contacts = new ArrayList<>();
        Cursor cursor = database.rawQuery(querySql, null);
        while (!cursor.isClosed() && cursor.moveToNext()) {
            ContactEntity entity = new ContactEntity();
            entity.setId(cursor.getInt(cursor.getColumnIndex(ContactSQLHelper.ID)));
            entity.setDialer_id(cursor.getString(cursor.getColumnIndex(ContactSQLHelper.DIALERID)));
            entity.setDialer_name(cursor.getString(cursor.getColumnIndex(ContactSQLHelper.DIALERNAME)));
            entity.setDialer_head_url(cursor.getString(cursor.getColumnIndex(ContactSQLHelper.DIALERHEADURL)));
            entity.setUser_id(cursor.getString(cursor.getColumnIndex(ContactSQLHelper.USERID)));
            entity.setUser_name(cursor.getString(cursor.getColumnIndex(ContactSQLHelper.USERNAME)));
            entity.setStart_time(cursor.getLong(cursor.getColumnIndex(ContactSQLHelper.STARTTIME)));
            entity.setDuration(cursor.getLong(cursor.getColumnIndex(ContactSQLHelper.DURATION)));
            entity.setConsumed_key(cursor.getLong(cursor.getColumnIndex(ContactSQLHelper.CONSUMEDKEY)));
            entity.setDaile_or_call("true".equals(cursor.getString(cursor.getColumnIndex(ContactSQLHelper.DAILORCALL))));
            entity.setVersion(cursor.getInt(cursor.getColumnIndex(ContactSQLHelper.VERSION)));
            contacts.add(entity);
        }
        closeCursor(cursor);
        closeDateBase(database);*/
        return getList(querySql);
    }
}
