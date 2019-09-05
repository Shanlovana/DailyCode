package com.hengtong.henchat.dbbase.dbcontact;

import com.hengtong.henchat.dbbase.BasicEntity;

public class ContactEntity implements BasicEntity {

    private long id = -1;
    private String dialer_id;
    private String dialer_name;
    private String dialer_head_url;
    private String user_id;
    private String user_name;
    private long start_time;
    private long duration;
    private long consumed_key;
    private boolean daile_or_call;
    private int version;

    public ContactEntity() {
    }

    public ContactEntity(String dialer_id, String dialer_name, String dialer_head_url, String user_id,
                         String user_name, long start_time, long duration, long consumed_key, boolean daile_or_call, int version) {
        this.dialer_id = dialer_id;
        this.dialer_name = dialer_name;
        this.dialer_head_url = dialer_head_url;
        this.user_id = user_id;
        this.user_name = user_name;
        this.start_time = start_time;
        this.duration = duration;
        this.consumed_key = consumed_key;
        this.daile_or_call = daile_or_call;
        this.version = version;
    }

    @Override
    public long getId() {
        return id;
    }

    public void setId(long id) {
        this.id = id;
    }

    public String getDialer_id() {
        return dialer_id;
    }

    public void setDialer_id(String dialer_id) {
        this.dialer_id = dialer_id;
    }

    public String getDialer_name() {
        return dialer_name;
    }

    public void setDialer_name(String dialer_name) {
        this.dialer_name = dialer_name;
    }

    public String getDialer_head_url() {
        return dialer_head_url;
    }

    public void setDialer_head_url(String dialer_head_url) {
        this.dialer_head_url = dialer_head_url;
    }

    public String getUser_id() {
        return user_id;
    }

    public void setUser_id(String user_id) {
        this.user_id = user_id;
    }

    public String getUser_name() {
        return user_name;
    }

    public void setUser_name(String user_name) {
        this.user_name = user_name;
    }

    public long getStart_time() {
        return start_time;
    }

    public void setStart_time(long start_time) {
        this.start_time = start_time;
    }

    public long getDuration() {
        return duration;
    }

    public void setDuration(long duration) {
        this.duration = duration;
    }

    public long getConsumed_key() {
        return consumed_key;
    }

    public void setConsumed_key(long consumed_key) {
        this.consumed_key = consumed_key;
    }

    public boolean isDaile_or_call() {
        return daile_or_call;
    }

    public void setDaile_or_call(boolean daile_or_call) {
        this.daile_or_call = daile_or_call;
    }

    public int getVersion() {
        return version;
    }

    public void setVersion(int version) {
        this.version = version;
    }

    @Override
    public String toString() {
        return "ContactEntity{" +
                "id=" + id +
                ", dialer_id='" + dialer_id + '\'' +
                ", dialer_name='" + dialer_name + '\'' +
                ", dialer_head_url='" + dialer_head_url + '\'' +
                ", user_id='" + user_id + '\'' +
                ", user_name='" + user_name + '\'' +
                ", start_time=" + start_time +
                ", duration=" + duration +
                ", consumed_key=" + consumed_key +
                ", daile_or_call=" + daile_or_call +
                ", version=" + version +
                '}';
    }
}
