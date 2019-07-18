# TipsCandCplusplus  
1. Change the value of constant variable  
    /* We can change the value of constant local variable with below function*/  
    /* Do not use this technique for constant global variable => Segmentation fault  
    The reason are:  
        - Initialized Data Segment can be classified 2 areas( read only area and write-read area).  
        - Constant global and static variable are stored in read only area of initialized data segment.  
        => So, when we try to change value of constant global variable will be violated memory management.  
    #*/  
2. Bit Masking and Shifting  
    ■1 byte 変数で設定できるため、 2 bytes変数が変換されること  
    ■1 byte 変数で設定できるため、 4 bytes変数が変換されること　　
    ■注意項目　　
        もし encode側は encode方が変更される時、decode側も変更必要です。　　
        例えば:　　
            encode側は4bytesのencode方を使った場合:　　
                - decode側も4bytesのdecode方を使わなければなりません。　　
                - もしdecode側は2bytesのdecode方を使ったら、取得結果は間違いはずです.  
            
3. Use Doxygen to parses the sources and generates the documentation.  
    - install graphviz-2.40.1  
    - create a doxygen configuration file (Doxyfile)  
    - modify doxygen configuration file  
    - run doxygen.   
    * Refer to make_doxygen.bat and Doxyfile
