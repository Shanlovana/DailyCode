package com.hengtong.henchat.dbbase.dbcontact;

import android.content.Context;

import com.blankj.utilcode.util.StringUtils;
import com.hengtong.henchat.constant.HenConstant;

import java.util.ArrayList;
import java.util.List;

public class ContactManager {
    private static ContactManager _instance;
    private static String TAG = "ContactManager";
    private static DBContactStore dbContactStore;
    private DBContactStore.ContactStoreListener contactStoreListener;


    private ContactManager() {
    }

    public static ContactManager getInstance(Context context) {
        if (_instance == null) {
            _instance = new ContactManager();
            dbContactStore = new DBContactStore(context.getApplicationContext());
        }
        return _instance;
    }

    /*changed version*/
    public List<List<ContactEntity>> getAllContactHis() {
        List<List<ContactEntity>> hashMap = new ArrayList<>();
        List<ContactEntity> list = dbContactStore.getContactIds(false);
        if (null != list && list.size() > 0) {
            for (int i = 0; i < list.size(); i++) {
                List<ContactEntity> idGroupList = dbContactStore.get(list.get(i).getDialer_id());
                if (idGroupList != null && idGroupList.size() > 0) hashMap.add(idGroupList);
            }
        }
        return hashMap;
    }

    public void setDBContactStoreListener(DBContactStore.ContactStoreListener contactStoreListener) {
        if (dbContactStore != null && contactStoreListener != null) {
            dbContactStore.setContactStoreStoreListener(contactStoreListener);
        }
        this.contactStoreListener = contactStoreListener;
    }

    public DBContactStore.ContactStoreListener getContactStoreListener() {
        return this.contactStoreListener;
    }

    /*    public HashMap<String, List<ContactEntity>> getAllContactHis(Context context) {
            HashMap<String, List<ContactEntity>> hashMap = new HashMap<>();
            DBContactStore dbContactStore = new DBContactStore(context);
            List<ContactEntity> list = dbContactStore.getContactIds(false);
            if (null != list && list.size() > 0) {
                for (int i = list.size() - 1; i >= 0; i--) {
                    ContactEntity contactEntity = list.get(i);
                    LogUtils.dTag(TAG, "getDialer_id is " + contactEntity.getDialer_id() + "  getStart_time is " + contactEntity.getStart_time());
                    List<ContactEntity> idList = dbContactStore.get(contactEntity.getDialer_id());
                    if (idList != null && idList.size() > 0) {
                        hashMap.put(contactEntity.getDialer_id(), idList);
                    }
                }
            }
            return hashMap;
        }*/

    //not finish version
    public List<List<ContactEntity>> getAllTactsHis(Context context) {
        List<List<ContactEntity>> lists = new ArrayList<>();
        List<ContactEntity> list = dbContactStore.queryByAll(HenConstant.SQLITEFORALL);
        if (list != null && list.size() > 0) {
            String dialerId = "";
            for (int i = 0; i < list.size(); i++) {
                List<ContactEntity> idGroupList;
                if (!StringUtils.equals(list.get(i).getDialer_id(), dialerId)) {
                    idGroupList = new ArrayList<>();
                }


            }
        }
        return lists;
    }

    public void add(ContactEntity contactEntity) {
        dbContactStore.add(contactEntity);
    }

    public boolean remove(String dialerId) {
        return dbContactStore.removeGroup(dialerId);

    }
    public boolean removeAll(){
        return dbContactStore.removeAll();
    }
}
