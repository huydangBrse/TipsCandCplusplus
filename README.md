# TipsCandCplusplus
1. Change the value of constant variable
  /* We can change the value of constant local variable with below function*/
  /* Do not use this technique for constant global variable => Segmentation fault
      The reason are:
          - Initialized Data Segment can be classified 2 areas( read only area and write-read area).
          - Constant global and static variable are stored in read only area of initialized data segment.
          => So, when we try to change value of constant global variable will be violated memory management.
  */
  <a href="https://cdncontribute.geeksforgeeks.org/wp-content/uploads/memoryLayoutC.jpg"> </a>
  void ChangeConstVariable()
  {
      const int a = 10;
      int* ptrTemp;
      ptrTemp = &a;
      *ptrTemp = 100;
      printf("\nValue changed = %d\n", a);
  }
