#ifndef __ISSUE__NO20__
#define __ISSUE__NO20__

namespace NO20 {
    void getLongestCommonSub(const char* str1, const char* str2, vector<char> &result) {
        vector<char> tmp_ret;
        size_t length1 = strlen(str1);
        size_t lenght2 = strlen(str2);
        int **matrix = (int **)(new int[length1]);
        size_t i, j;
        for (i = 0; i < length1; i++) {
            matrix[i] = new int[lenght2];
        }
        for (i = 0; i < length1; i++) {
            for (j = 0; j < lenght2; j++) {
                matrix[i][j] = 0;
            }
        }

    }

    // directions of LCS generation
enum decreaseDir {kInit = 0, kLeft, kUp, kLeftUp};
void LCS_Print(int **LCS_direction,
                    char* pStr1, char* pStr2,
                    size_t row, size_t col);

/////////////////////////////////////////////////////////////////////////////
// Get the length of two strings' LCSs, and print one of the LCSs
// Input: pStr1         - the first string
//        pStr2         - the second string
// Output: the length of two strings' LCSs
/////////////////////////////////////////////////////////////////////////////
int LCS(char* pStr1, char* pStr2)
{
      if(!pStr1 || !pStr2)
            return 0;

      size_t length1 = strlen(pStr1);
      size_t length2 = strlen(pStr2);
      if(!length1 || !length2)
            return 0;

      size_t i, j;

      // initiate the length matrix
      int **LCS_length;
      LCS_length = (int**)(new int[length1]);
      for(i = 0; i < length1; ++ i)
            LCS_length[i] = (int*)new int[length2];

      for(i = 0; i < length1; ++ i)
            for(j = 0; j < length2; ++ j)
                  LCS_length[i][j] = 0;



      // initiate the direction matrix
      int **LCS_direction;
      LCS_direction = (int**)(new int[length1]);
      for( i = 0; i < length1; ++ i)
            LCS_direction[i] = (int*)new int[length2];

      for(i = 0; i < length1; ++ i)
            for(j = 0; j < length2; ++ j)
                  LCS_direction[i][j] = kInit;

      for(i = 0; i < length1; ++ i)
      {
            for(j = 0; j < length2; ++ j)
            {
                  if(i == 0 || j == 0)
                  {
                        if(pStr1[i] == pStr2[j])
                        {
                              LCS_length[i][j] = 1;
                              LCS_direction[i][j] = kLeftUp;
                        }
                        else
                              LCS_length[i][j] = 0;
                  }
                  // a char of LCS is found,
                  // it comes from the left up entry in the direction matrix
                  else if(pStr1[i] == pStr2[j])
                  {
                        LCS_length[i][j] = LCS_length[i - 1][j - 1] + 1;
                        LCS_direction[i][j] = kLeftUp;
                  }
                  // it comes from the up entry in the direction matrix
                  else if(LCS_length[i - 1][j] > LCS_length[i][j - 1])
                  {
                        LCS_length[i][j] = LCS_length[i - 1][j];
                        LCS_direction[i][j] = kUp;
                  }
                  // it comes from the left entry in the direction matrix
                  else
                  {
                        LCS_length[i][j] = LCS_length[i][j - 1];
                        LCS_direction[i][j] = kLeft;
                  }
            }
      }
      LCS_Print(LCS_direction, pStr1, pStr2, length1 - 1, length2 - 1);

      return LCS_length[length1 - 1][length2 - 1];
}



/////////////////////////////////////////////////////////////////////////////
// Print a LCS for two strings
// Input: LCS_direction - a 2d matrix which records the direction of
//                        LCS generation
//        pStr1         - the first string
//        pStr2         - the second string
//        row           - the row index in the matrix LCS_direction
//        col           - the column index in the matrix LCS_direction
/////////////////////////////////////////////////////////////////////////////
void LCS_Print(int **LCS_direction,
                    char* pStr1, char* pStr2,
                    size_t row, size_t col)
{
      if(pStr1 == NULL || pStr2 == NULL)
            return;

      size_t length1 = strlen(pStr1);
      size_t length2 = strlen(pStr2);

      if(length1 == 0 || length2 == 0 || !(row < length1 && col < length2))
            return;

      // kLeftUp implies a char in the LCS is found
      if(LCS_direction[row][col] == kLeftUp)
      {
            if(row > 0 && col > 0)
                  LCS_Print(LCS_direction, pStr1, pStr2, row - 1, col - 1);

            // print the char
            printf("%c", pStr1[row]);
      }
      else if(LCS_direction[row][col] == kLeft)
      {
            // move to the left entry in the direction matrix
            if(col > 0)
                  LCS_Print(LCS_direction, pStr1, pStr2, row, col - 1);
      }
      else if(LCS_direction[row][col] == kUp)
      {
            // move to the up entry in the direction matrix
            if(row > 0)
                  LCS_Print(LCS_direction, pStr1, pStr2, row - 1, col);
      }
}

    void testLCS() {
        const char* str1 = "BDCABA";
        const char* str2 = "ABCBDAB";
        LCS(const_cast<char*>(str1), const_cast<char*>(str2));
    }
}

#endif // __ISSUE__NO20__
