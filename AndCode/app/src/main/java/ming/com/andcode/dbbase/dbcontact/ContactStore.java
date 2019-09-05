package com.hengtong.henchat.dbbase.dbcontact;

import java.util.HashMap;
import java.util.List;

public interface ContactStore {

    void add(ContactEntity contactEntity);

    List<ContactEntity> get(String date);

    HashMap<String, List<ContactEntity>> getContacts();

     List<ContactEntity> queryByAll(String sql);

    List<ContactEntity> getContactIds(boolean all);

    boolean remove(long contactDetailId);

    boolean removeGroup(String dialerId);

    boolean removeAll();


}
