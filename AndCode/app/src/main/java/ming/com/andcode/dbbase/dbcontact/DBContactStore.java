package com.hengtong.henchat.dbbase.dbcontact;

import android.content.Context;

import com.blankj.utilcode.util.LogUtils;
import com.hengtong.henchat.dbbase.BaseDao;
import com.hengtong.henchat.dbbase.Where;

import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;
import java.util.List;
import java.util.concurrent.locks.Lock;
import java.util.concurrent.locks.ReentrantLock;

public class DBContactStore implements ContactStore {


    /**
     * Contact max count in disk.
     */
    private final static int MAX_CONTACT_SIZE = 1000;
    /**
     * Database sync lock.
     */
    private Lock mLock;

    /**
     * Cookie entity dao.
     */
    private BaseDao<ContactEntity> mContactEntityDao;

    private ContactStoreListener mContactStoreListener;

    private boolean mEnable = true;

    public DBContactStore(Context context) {
        mLock = new ReentrantLock();
        mContactEntityDao = new ContactEntityDao(context);
    }


    /**
     * The callback when adding and deleting cookies.
     */
    public DBContactStore setContactStoreStoreListener(ContactStoreListener ContactStorStoreListener) {
        this.mContactStoreListener = ContactStorStoreListener;
        return this;
    }

    public DBContactStore setEnable(boolean enable) {
        this.mEnable = enable;
        return this;
    }

    @Override
    public void add(ContactEntity contactEntity) {
        mLock.lock();
        try {
            if (mEnable && contactEntity != null) {
                mContactEntityDao.replace(contactEntity);
                if (mContactStoreListener != null) {
                    mContactStoreListener.onSaveContact(contactEntity);
                }
                trimSize();
            }
        } finally {
            mLock.unlock();
        }
    }

    @Override
    public List<ContactEntity> get(String date) {
        //TODO  do it later
        mLock.lock();
        try {
            if (isEmpty(date) || !mEnable) return Collections.emptyList();
            Where subWhere = new Where(ContactSQLHelper.DIALERID, Where.Options.EQUAL, date);
            List<ContactEntity> list = mContactEntityDao.getList(subWhere.get(), ContactSQLHelper.STARTTIME, true, null, null, null);
            return (list == null || list.size() < 1) ? Collections.<ContactEntity>emptyList() : list;
        } finally {
            mLock.unlock();
        }
    }

    @Override
    public HashMap<String, List<ContactEntity>> getContacts() {
        mLock.lock();
        return null;
    }

    @Override
    public List<ContactEntity> queryByAll(String sql) {
        List<ContactEntity> list = mContactEntityDao.queryByAll(sql, false);
        return (list == null || list.size() < 1) ? Collections.<ContactEntity>emptyList() : list;
    }


    @Override
    public List<ContactEntity> getContactIds(boolean all) {
        mLock.lock();
        List<ContactEntity> list = mContactEntityDao.getList(null, ContactSQLHelper.STARTTIME, true, all ? null : ContactSQLHelper.DIALERID, null, null);
        if (list == null || list.size() < 1) return Collections.emptyList();
        return list;
    }

    /*alone*/
    @Override
    public boolean remove(long start_time) {
        mLock.lock();
        try {
            if (!mEnable) return false;
            Where delete = new Where(ContactSQLHelper.STARTTIME, Where.Options.EQUAL, start_time);
            return mContactEntityDao.delete(delete.toString());
        } finally {
            mLock.unlock();
        }
    }

    /*remove group*/
    @Override
    public boolean removeGroup(String dialerId) {
        mLock.lock();
        try {
            if (!mEnable) return false;
            Where delete = new Where(ContactSQLHelper.DIALERID, Where.Options.EQUAL, dialerId);
            boolean deleteSu = mContactEntityDao.delete(delete.toString());
            if (deleteSu && mContactStoreListener != null) {
                mContactStoreListener.onRemoveContactGroup(dialerId);
            }
            return deleteSu;
        } finally {
            mLock.unlock();
        }
    }

    @Override
    public boolean removeAll() {
        mLock.lock();
        try {
            return mEnable && mContactEntityDao.deleteAll();
        } finally {
            mLock.unlock();
        }
    }


    /*
     * Trim the list.
     */
    private void trimSize() {
        int count = mContactEntityDao.count();
        if (count > MAX_CONTACT_SIZE + 10) {
            List<ContactEntity> rmList = mContactEntityDao.getList(null, null, true, null, Integer.toString(count -
                    MAX_CONTACT_SIZE), null);
            if (rmList != null)
                mContactEntityDao.delete(rmList);
        }
    }

    private boolean isEmpty(String data) {
        return data == null || data.length() == 0;
    }


    public interface ContactStoreListener {

        void onSaveContact(ContactEntity contactEntity);


        void onRemoveContact(long startTime);

        void onRemoveContactGroup(String dialerId);

        void onRemoveAll();

    }


}
