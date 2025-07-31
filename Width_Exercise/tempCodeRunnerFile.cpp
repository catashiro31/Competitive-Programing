dp[i+1][j][k] = (i+1-a+j-b+k-c)/(i+j+k) * dp[i][j][k];
                // dp[i][j+1][k] = (i-a+j+1-b+k-c)/(i+j+k) * dp[i][j][k];
                // dp[i][j][k+1] = (i-a+j-b+k+1-c)/(i+j+k) * dp[i][j][k];
                // if (i+1 == 100) kq += dp[100][j][k];
                // else if (j+1 == 100) kq += dp[i][100][k];
                // else if (k+1 == 100) kq += dp[i][j][100]; 