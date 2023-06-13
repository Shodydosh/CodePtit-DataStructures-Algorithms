### TIEN TO -> TRUNG TO && TIEN TO -> HAU TO

```cpp
bool isValid(char c)
{
    if (c == '+' || c == '-' || c == '*' || c == '/')
        return true;
    return false;
}

string cal(string s)
{
    stack<string> st;
    reverse(all(s));
    for (char c : s)
    {
        if (!isValid(c))
        {
            string tmp = "";
            tmp += c;
            st.push(tmp);
        }
        else
        {
            string a = st.top();
            st.pop();
            string b = st.top();
            st.pop();
            st.push("(" + a + c + b + ")");
            // st.push(a + b + c);
        }
    }
    return st.top() + '\n';
}

main()
{
    faster();
    run()
    {
        string s;
        getline(cin, s);
        cout << cal(s);
    }
}
```

### HAU TO -> TIEN TO, HAU TO -> TRUNG TO

```cpp
bool isValid(char c)
{
    if (c == '+' || c == '-' || c == '*' || c == '/')
        return true;
    return false;
}

string cal(string s)
{
    stack<string> st;
    for (char c : s)
    {
        if (!isValid(c))
        {
            string tmp = "";
            tmp += c;
            st.push(tmp);
        }
        else
        {
            string a = st.top();
            st.pop();
            string b = st.top();
            st.pop();
            st.push(c + b + a);
            st.push("(" + b + c + a + ")");
        }
    }
    return st.top() + '\n';
}

main()
{
    faster();
    int t;
    cin >> t;
    cin.ignore();
    while (t--)
    {
        string s;
        cin >> s;
        cout << cal(s);
    }
}
```

### TINH GIA TRI HAU TO && TIEN TO

```cpp
bool isValid(char c)
{
    if (c == '+' || c == '-' || c == '*' || c == '/')
        return true;
    return false;
}

string calculate(int a, int b, char x)
{
    // cout << a << ' ' << b << endl;
    if (x == '+')
        return to_string(a + b);
    if (x == '-')
        return to_string(a - b);
    if (x == '*')
        return to_string(a * b);
    return to_string(a / b);
}

string cal(string s)
{
    stack<string> st;
    for (char c : s)
    {
        if (!isValid(c))
        {
            string tmp = "";
            tmp += c;
            st.push(tmp);
        }
        else
        {
            string a = st.top();
            st.pop();
            string b = st.top();
            st.pop();
            st.push(calculate(stoi(b), stoi(a), c));
            // st.push(calculate(stoi(a), stoi(b), c)); // <- TIEN TO
        }
    }
    return st.top() + '\n';
}

main()
{
    faster();
    int t;
    cin >> t;
    cin.ignore();
    while (t--)
    {
        string s;
        cin >> s;
        cout << cal(s);
    }
}
```

### DAY NGOAC DUNG DAI NHAT

```cpp
int cal(string s)
{
    stack<int> st;
    int res = 0, cnt = 0;
    st.push(-1);
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '(')
            st.push(i);
        else
        {
            st.pop();
            if (st.size())
                res = max(res, i - st.top());
            else if (st.empty())
                st.push(i);
        }
    }
    return res;
}
```

### BIEU THUC TANG GIAM

A[] = “I” : số tăng nhỏ nhất là 12.
A[] = “D” : số giảm nhỏ nhất là 21
A[] =”DD” : số giảm nhỏ nhất là 321
A[] = “DDIDDIID”: số thỏa mãn 321654798

```cpp
main()
{
    faster();
    run()
    {
        string s, ans = "";
        cin >> s;
        stack<int> st;
        for (int i = 0; i <= s.length(); i++)
        {
            st.push(i + 1);
            if (i == s.length() || s[i] == 'I')
                while (!st.empty())
                {
                    ans += to_string(st.top());
                    st.pop();
                }
        }
        cout << ans << endl;
    }
}
```

### HINH CHU NHAT LON NHAT

```cpp
main()
{
    faster();
    run()
    {
        int n;
        cin >> n;
        long long res = INT_MIN;
        long long H[n], L[n], R[n];
        // R là số bên phải lớn hơn đầu tiên, kể cả chính nó.
        // L là số bên trái lớn hơn đầu tiên, kể cả chính nó.
        for (int i = 0; i < n; i++)
            cin >> H[i];
        stack<int> st;

        st.push(-1);
        for (int i = 0; i < n; i++)
        {
            while (st.size() > 1 && H[st.top()] >= H[i])
                st.pop();
            L[i] = st.top() + 1;
            st.push(i);
        }
        while (st.size())
            st.pop();

        st.push(n);
        for (int i = n - 1; i >= 0; i--)
        {
            while (st.size() > 1 && H[st.top()] >= H[i])
                st.pop();
            R[i] = st.top() - 1;
            st.push(i);
        }

        for (int i = 0; i < n; i++)
            res = max(res, H[i] * (R[i] - L[i] + 1));
        cout << res << endl;
    }
}
```
