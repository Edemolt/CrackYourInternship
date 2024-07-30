#include <bits/stdc++.h>
using namespace std;

// a function to handle the strong suffix case.
void preprocess_suffix(int *shift, int *borderPosition,
                       char *pattern, int m) {
   int i = m, j = m + 1;
   borderPosition[i] = j;

   // traversing until the size of the pattern is greater than 0
   while (i > 0) {
      /*
      If the character at position (i-1) is not the same as the character at (j-1), then continue the algorithm.
      */
      while (j <= m && pattern[i - 1] != pattern[j - 1]) {
         if (shift[j] == 0)
            shift[j] = j - i;

         // Updating the position of the next border
         j = borderPosition[j];
      }
      /*
      Since p[i-1] is matched with p[j-1] then we have found the border, then store the border.
      */
      i--;
      j--;
      borderPosition[i] = j;
   }
}

// a function to handle the prefix case.
void preprocess_prefix(int *shift, int *borderPosition,
                       char *pattern, int m) {
   int i, j;
   j = borderPosition[0];
   for (i = 0; i <= m; i++) {
      /*
      setting the border position of the pattern's first character to all the indices in the shift array.
      */
      if (shift[i] == 0)
         shift[i] = j;

      /* suffix becomes shorter than borderPosition[0], use the position of the next widest border as the value of j.

      Now if the suffix becomes shorter than borderPosition[0], we need to use the next position of
      the widest border as the new value of j.
      */
      if (i == j)
         j = borderPosition[j];
   }
}

// A function that searches the string and returns the occurrence.
void BoyerMooreAlgorithm(char *text, char *pattern) {
   // s is a shift of the pattern concerning input text.
   int s = 0, j;
   int m = strlen(pattern);
   int n = strlen(text);

   // an array to store the shifts and
   // borderPosition will store the widest border of the pattern
   int borderPosition[m + 1], shift[m + 1];

   // initialize all occurrences of the shift to 0
   for (int i = 0; i < m + 1; i++)
      shift[i] = 0;

   // first performing the preprocessing
   preprocess_suffix(shift, borderPosition, pattern, m);
   preprocess_prefix(shift, borderPosition, pattern, m);

   while (s <= n - m) {

      j = m - 1;

      // If the pattern and text are matching, keep on reducing the j variable.
      while (j >= 0 && pattern[j] == text[s + j])
         j--;

      // If the pattern is a represencurrentnt shift, then j will become -1.
      if (j < 0) {
         cout << "Pattern found at index:" << s << endl;
         s += shift[0];
      }
      else
         /*
         pattern[i] != pattern[s+j] so Shifting the pattern so that the bad character of the text is aligned
         */
         s += shift[j + 1];
   }
}

int main() {
   char text[] = "he is doing what he was supposed to do.";
   char pattern[] = "he";

   BoyerMooreAlgorithm(text, pattern);

   return 0;
}
