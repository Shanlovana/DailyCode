package ming.com.basemodule;

import android.os.Parcel;
import android.os.Parcelable;

public class Books implements Parcelable {
   private String bookName;
   private int bookPrice;
   private int bookId;
   private String bookPublish;

    protected Books(Parcel in) {
        bookName = in.readString();
        bookPrice = in.readInt();
        bookId = in.readInt();
        bookPublish = in.readString();
    }

    public Books(String bookName, int bookPrice, int bookId, String bookPublish) {
        this.bookName = bookName;
        this.bookPrice = bookPrice;
        this.bookId = bookId;
        this.bookPublish = bookPublish;
    }

    public static final Creator<Books> CREATOR = new Creator<Books>() {
        @Override
        public Books createFromParcel(Parcel in) {
            return new Books(in);
        }

        @Override
        public Books[] newArray(int size) {
            return new Books[size];
        }
    };

    @Override
    public int describeContents() {
        return 0;
    }

    @Override
    public void writeToParcel(Parcel parcel, int i) {
        parcel.writeString(bookName);
        parcel.writeInt(bookPrice);
        parcel.writeInt(bookId);
        parcel.writeString(bookPublish);
    }
}
