#include <stdio.h>
#include <string.h>
#define MAX 105
char name[MAX][15];
int friend[MAX][MAX];
int cnt[MAX];
int total = 0;
int find(char *s) {
    for (int i = 0; i < total; i++)
        if (strcmp(name[i], s) == 0)
            return i;
    strcpy(name[total], s);
    return total++;
}
int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    memset(friend, 0, sizeof(friend));
    memset(cnt, 0, sizeof(cnt));
    for (int i = 0; i < m; i++) {
        char a[15], b[15];
        scanf("%s%s", a, b);
        int x = find(a);
        int y = find(b);
        if (friend[x][y] == 0) {
            friend[x][y] = 1;
            friend[y][x] = 1;
            cnt[x]++;
            cnt[y]++;
        }
    }
    int max = 0;
    for (int i = 0; i < total; i++)
        if (cnt[i] > max)
            max = cnt[i];
    printf("%d\n", max);
    return 0;
}
// #include <stdio.h>
// #include <string.h>

// int main() {
//     int n, m;
//     scanf("%d %d", &n, &m);

//     char name[101][11];
//     int arr[101][101] = {0};
//     int cnt = 0;

//     for (int i = 0; i < m; i++) {
//         char temp_name1[11], temp_name2[11];
//         int appear1 = 0, appear2 = 0;
//         int locate1 = 0, locate2 = 0;

//         scanf("%s %s", temp_name1, temp_name2);

//         for (int j = 0; j < cnt; j++) {
//             if (strcmp(temp_name1, name[j]) == 0) {
//                 appear1 = 1;
//                 locate1 = j;
//             }
//             if (strcmp(temp_name2, name[j]) == 0) {
//                 appear2 = 1;
//                 locate2 = j;
//             }
//         }

//         if (!appear1) {
//             strcpy(name[cnt], temp_name1);
//             locate1 = cnt;
//             cnt++;
//         }
//         if (!appear2) {
//             strcpy(name[cnt], temp_name2);
//             locate2 = cnt;
//             cnt++;
//         }

//         arr[locate1][locate2] = 1;
//         arr[locate2][locate1] = 1;
//     }

//     int max = 0;
//     for (int i = 0; i < cnt; i++) {
//         int num = 0;
//         for (int j = 0; j < cnt; j++) {
//             if (arr[i][j] == 1) num++;
//         }
//         if (num > max) max = num;
//     }

//     printf("%d\n", max);
//     return 0;
// }