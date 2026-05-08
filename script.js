function unlock() {
    const pass = document.getElementById('master-pass').value;
    
    // الرمز الرسمي هو 1234
    if(pass === "1234") {
        alert("أهلاً بكم فريق المبدعين! النظام جاهز للعمل.");
        
        // إخفاء قسم الدخول وإظهار لوحة التحكم
        document.getElementById('login-section').style.display = 'none';
        document.getElementById('main-content').style.display = 'block';
    } else {
        alert("الرمز غير صحيح، حاول مرة أخرى.");
    }
}
