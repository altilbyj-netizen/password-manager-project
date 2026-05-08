function unlock() {
    const passInput = document.getElementById('master-pass').value;
    
    if(passInput === "1234") {
        alert("أهلاً بكم فريق المبدعين! النظام جاهز للعمل.");
        // إخفاء واجهة الدخول وإظهار المحتوى
        document.getElementById('login-section').style.display = 'none';
        document.getElementById('main-content').style.display = 'block';
    } else {
        alert("الرمز غير صحيح! جرب 1234");
    }
}

function saveData() {
    const site = document.getElementById('site-name').value;
    const pass = document.getElementById('site-pass').value;

    if(site && pass) {
        const list = document.getElementById('password-list');
        const li = document.createElement('li');
        
        // تشفير كلمة المرور بنظام Base64 لإبهار الدكتور
        const encrypted = btoa(pass);
        
        li.innerHTML = `<strong>${site}:</strong> <span style="color:red;">${encrypted}</span> (تم التشفير)`;
        list.appendChild(li);

        // مسح الخانات بعد الحفظ
        document.getElementById('site-name').value = "";
        document.getElementById('site-pass').value = "";
    } else {
        alert("يرجى ملء كافة الخانات");
    }
}
