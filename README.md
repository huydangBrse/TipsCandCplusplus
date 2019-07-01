# TipsCandCplusplus  
1. Change the value of constant variable  
    /* We can change the value of constant local variable with below function*/  
    /* Do not use this technique for constant global variable => Segmentation fault  
    The reason are:  
        - Initialized Data Segment can be classified 2 areas( read only area and write-read area).  
        - Constant global and static variable are stored in read only area of initialized data segment.  
        => So, when we try to change value of constant global variable will be violated memory management.  
    #*/  
    <a href="https://cdncontribute.geeksforgeeks.org/wp-content/uploads/memoryLayoutC.jpg"> </a>  
    void ChangeConstVariable()  
    {  
        const int a = 10;  
        int* ptrTemp;  
        ptrTemp = &a;  
        *ptrTemp = 100;  
        printf("\nValue changed = %d\n", a);  
    }

2. Bit Masking and Shifting  
    ■1 byte 変数で設定できるため、 4 bytes変数が変換されること  
    encode  
        unsigned long　value;  
        uint8 bytes[4];  
        bytes[0] = (byte) ((value & 0xFF000000) >> 24 );  
        bytes[1] = (byte) ((value & 0x00FF0000) >> 16 );  
        bytes[2] = (byte) ((value & 0x0000FF00) >> 8  );  
        bytes[3] = (byte) ((value & 0X000000FF)       );  
    decode  
        value =   (bytes[0] << 24)  
                + (bytes[1] << 16)  
                + (bytes[2] << 8)  
                + (bytes[3]);　　

    例：　　
        errorInfo  = 0x80000000U  
        encode:　　
                       0x1000.0000.0000.0000.0000.0000.0000.0000　　
                       0x1111.1111.0000.0000.0000.0000.0000.0000　　
                    -----------------AND---------------------　　
            bytes[0] = 0x1000.0000.0000.0000.0000.0000.0000.0000 >> 24　　
                     = 0x0000.0000.0000.0000.0000.0000.1000.0000　　
                     = 0x10　　

                       0x1000.0000.0000.0000.0000.0000.0000.0000　　
                       0x0000.0000.1111.1111.0000.0000.0000.0000　　
                    -----------------AND---------------------　　
            bytes[1] = 0x0000.0000.0000.0000.0000.0000.0000.0000 >> 16　　
                     = 0x0000.0000.0000.0000.0000.0000.0000.0000　　
                     = 0x00　　

                       0x1000.0000.0000.0000.0000.0000.0000.0000　　
                       0x0000.0000.0000.0000.1111.1111.0000.0000　　
                    -----------------AND---------------------　　
            bytes[2] = 0x0000.0000.0000.0000.0000.0000.0000.0000 >> 8　　
                     = 0x0000.0000.0000.0000.0000.0000.0000.0000　　
                     = 0x00　　

                       0x1000.0000.0000.0000.0000.0000.0000.0000　　
                       0x0000.0000.0000.0000.0000.0000.1111.1111　　
                    -----------------AND---------------------　　
            bytes[3] = 0x0000.0000.0000.0000.0000.0000.0000.0000　　
                     = 0x00　　
    decode:　　
        value =   (bytes[0] << 24)　　
                + (bytes[1] << 16)　　
                + (bytes[2] << 8)　　
                +  bytes[3]　　
              =   (0x0000.0000.0000.0000.0000.0000.1000.0000 << 24)　　
                + (0x0000.0000.0000.0000.0000.0000.0000.0000 << 16)　　
                + (0x0000.0000.0000.0000.0000.0000.0000.0000 << 8)　　
                + (0x0000.0000.0000.0000.0000.0000.0000.0000)　　
              =    0x1000.0000.0000.0000.0000.0000.0000.0000　　
                +  0x0000.0000.0000.0000.0000.0000.0000.0000　　
                +  0x0000.0000.0000.0000.0000.0000.0000.0000　　
                +  0x0000.0000.0000.0000.0000.0000.0000.0000　　
              =    0x1000.0000.0000.0000.0000.0000.0000.0000　　
              =    0x80000000　　
        => errorInfo = 0x80000000　　

    ■1 byte 変数で設定できるため、 4 bytes変数が変換されること　　
    encode　　
        unsigned short value;　　
        uint8 bytes[2]　　
        bytes[0] = (value & 0xFF00) >> 8;　　
        bytes[1] = (value & 0x00FF);　　

    decode　　
        value = (bytes[0] << 8)　　
               + bytes[1];　　

    例：　　
        errorInfo = 0x0800U　　　　
        encode:　　
                       0x0000.1000.0000.0000　　
                       0x1111.1111.0000.0000　　
                       -------AND-----------　　
            bytes[0] = 0x0000.1000.0000.0000 >> 8　　
                     = 0x0000.0000.0000.1000　　
                     = 0x08　　

                       0x0000.1000.0000.0000　　
                       0x0000.0000.1111.1111　　
                       ------AND------------　　
            bytes[1] = 0x0000.0000.0000.0000　　
                     = 0x00　　

        decode:　　
            value = (bytes[0] << 8)　　
                   + bytes[1];　　
                  = (0x0000.1000 << 8)　　
                    +0x0000.0000　　
                  = 0x1000.0000.0000 + 0x0000.0000　　
                  = 0x1000.0000.0000　　
                  =0.0800　　

■注意項目　　
    もし encode側は encode方が変更される時、decode側も変更必要です。　　
    例えば:　　
        encode側は4bytesのencode方を使った場合:　　
            - decode側も4bytesのdecode方を使わなければなりません。　　
            - もしdecode側は2bytesのdecode方を使ったら、取得結果は間違いはずです。　　
