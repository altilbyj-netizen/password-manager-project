function unlock() {
    const pass = document.getElementById('master-pass').value;
    if(pass === "1234") { // هاي الكلمة الرسمية تكدر تغيرها
        document.getElementById('login-section').style.display = 'none';
        document.getElementById('main-content').style.display = 'block';
    } else { alert("خطأ!"); }
}

function saveData() {
    const site = document.getElementById('site-name').value;
    const pass = document.getElementById('site-pass').value;
    if(site && pass) {
        const list = document.getElementById('password-list');
        const li = document.createElement('li');
        li.textContent = site + ": " + btoa(pass); // تشفير بسيط
        list.appendChild(li);
    }
}
