<!DOCTYPE html>
<html lang="ar" dir="rtl">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>مشروع PassSafe | جامعة بابل</title>
    <style>
        /* CSS - تنسيق الواجهة */
        :root {
            --primary-color: #2563eb;
            --bg-color: #f8fafc;
            --card-bg: #ffffff;
            --text-main: #1e293b;
            --accent-color: #64748b;
        }

        body {
            font-family: 'Segoe UI', Tahoma, Geneva, Verdana, sans-serif;
            background-color: var(--bg-color);
            color: var(--text-main);
            margin: 0;
            display: flex;
            justify-content: center;
            align-items: center;
            min-height: 100vh;
        }

        .container {
            background: var(--card-bg);
            width: 90%;
            max-width: 500px;
            padding: 2rem;
            border-radius: 20px;
            box-shadow: 0 10px 25px rgba(0,0,0,0.05);
            border: 1px solid #e2e8f0;
        }

        header {
            text-align: center;
            margin-bottom: 2rem;
        }

        .uni-tag {
            font-size: 0.85rem;
            color: var(--primary-color);
            font-weight: bold;
            margin-bottom: 0.5rem;
            display: block;
        }

        h1 {
            font-size: 1.8rem;
            margin: 0.5rem 0;
            color: #0f172a;
        }

        .subtitle {
            font-size: 0.95rem;
            color: var(--accent-color);
        }

        .card {
            background: #f1f5f9;
            padding: 1.5rem;
            border-radius: 12px;
            margin-bottom: 1.5rem;
        }

        input {
            width: 100%;
            padding: 12px;
            margin: 10px 0;
            border: 1px solid #cbd5e1;
            border-radius: 8px;
            box-sizing: border-box;
            font-size: 1rem;
        }

        button {
            width: 100%;
            padding: 12px;
            border: none;
            border-radius: 8px;
            background: var(--primary-color);
            color: white;
            font-weight: bold;
            cursor: pointer;
            transition: 0.3s;
        }

        button:hover {
            background: #1d4ed8;
        }

        #password-list {
            list-style: none;
            padding: 0;
            margin-top: 1rem;
        }

        #password-list li {
            background: white;
            padding: 10px;
            margin-bottom: 8px;
            border-radius: 6px;
            border-right: 4px solid var(--primary-color);
            display: flex;
            justify-content: space-between;
            font-size: 0.9rem;
        }

        footer {
            margin-top: 2rem;
            padding-top: 1.5rem;
            border-top: 1px solid #e2e8f0;
            text-align: center;
        }

        .team-title {
            font-weight: bold;
            font-size: 0.9rem;
            margin-bottom: 1rem;
            color: #475569;
        }

        .team-grid {
            display: flex;
            justify-content: center;
            gap: 10px;
            flex-wrap: wrap;
        }

        .member {
            background: #e2e8f0;
            padding: 4px 12px;
            border-radius: 15px;
            font-size: 0.85rem;
            font-weight: 500;
        }
    </style>
</head>
<body>

    <div class="container">
        <header>
            <span class="uni-tag">جامعة بابل | IT Babylon</span>
            <h1>🔐 PassSafe V1.0</h1>
            <p class="subtitle">نظام إدارة وتشفير كلمات المرور</p>
        </header>

        <div id="login-section" class="card">
            <p style="text-align: center; margin-top: 0;">الوصول الآمن للمشروع</p>
            <input type="password" id="master-pass" placeholder="أدخل كلمة المرور الرسمية...">
            <button onclick="unlock()">دخول للنظام</button>
        </div>

        <div id="main-content" style="display:none;" class="card">
            <h4 style="margin-top: 0;">إضافة بيانات جديدة</h4>
            <input type="text" id="site-name" placeholder="اسم الموقع (مثال: فيسبوك)">
            <input type="password" id="site-pass" placeholder="كلمة المرور المراد حفظها">
            <button onclick="saveData()" style="background: #059669;">تشفير وحفظ</button>
            <hr style="margin: 1.5rem 0; border: 0.5px solid #cbd5e1;">
            <ul id="password-list"></ul>
        </div>

        <footer>
            <p class="team-title">إعداد فريق العمل - قسم الشبكات:</p>
            <div class="team-grid">
                <span class="member">👤 جعفر سيف</span>
                <span class="member">👤 فاطمة محمد</span>
                <span class="member">👤 زهراء فائق</span>
            </div>
        </footer>
    </div>

    <script>
        /* JS - المنطق البرمجي */
        
        // دالة التشفير البسيط (Base64)
        function encrypt(text) {
            return btoa(text); 
        }

        // دالة فك التشفير
        function decrypt(text) {
            try {
                return atob(text);
            } catch(e) {
                return "خطأ في التشفير";
            }
        }

        function unlock() {
            const master = document.getElementById('master-pass').value;
            // كلمة المرور الرسمية هي "admin123"
            if(master === "admin123") {
                document.getElementById('login-section').style.display = 'none';
                document.getElementById('main-content').style.display = 'block';
                displayEntries();
            } else {
                alert("عذراً، كلمة المرور غير صحيحة!");
            }
        }

        function saveData() {
            const site = document.getElementById('site-name').value;
            const pass = document.getElementById('site-pass').value;

            if(site && pass) {
                const encryptedPass = encrypt(pass);
                const entry = { site, pass: encryptedPass };
                
                let passwords = JSON.parse(localStorage.getItem('teamPasswords') || "[]");
                passwords.push(entry);
                localStorage.setItem('teamPasswords', JSON.stringify(passwords));
                
                // مسح الخانات بعد الحفظ
                document.getElementById('site-name').value = "";
                document.getElementById('site-pass').value = "";
                
                displayEntries();
            } else {
                alert("يرجى ملء كافة الخانات!");
            }
        }

        function displayEntries() {
            const list = document.getElementById('password-list');
            const passwords = JSON.parse(localStorage.getItem('teamPasswords') || "[]");
            list.innerHTML = "<strong>كلمات المرور المحفوظة:</strong>";
            
            passwords.forEach(item => {
                const li = document.createElement('li');
                li.innerHTML = `<span>🌐 ${item.site}</span> <span>🔑 ${decrypt(item.pass)}</span>`;
                list.appendChild(li);
            });
        }
    </script>
</body>
</html>
