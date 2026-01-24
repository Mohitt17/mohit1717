window.addEventListener("load", function () {

    const submitForm = document.querySelector("footer form");

    // Auto-fill data if already saved
    const savedData = JSON.parse(localStorage.getItem("studentData"));
    if (savedData) {
        const inputs = document.querySelectorAll("#name");
        inputs[0].value = savedData.fname || "";
        inputs[1].value = savedData.lname || "";
        inputs[2].value = savedData.mobile || "";
    }

    submitForm.addEventListener("submit", function (e) {
        e.preventDefault();

        const inputs = document.querySelectorAll("#name");

        const fname = inputs[0].value.trim();
        const lname = inputs[1].value.trim();
        const mobile = inputs[2].value.trim();

        if (fname === "") {
            alert("Enter First Name");
            return;
        }

        if (lname === "") {
            alert("Enter Last Name");
            return;
        }

        if (!/^[0-9]{10}$/.test(mobile)) {
            alert("Enter valid 10-digit Mobile Number");
            return;
        }

        const favLang = document.querySelector('input[name="fav_language"]:checked');
        if (!favLang) {
            alert("Select favorite Web language");
            return;
        }

        const progLangs = document.querySelectorAll('input[type="checkbox"]:checked');
        if (progLangs.length === 0) {
            alert("Select at least one Programming language");
            return;
        }

        const degree = document.querySelector('input[name="Degree"]:checked');
        if (!degree) {
            alert("Select your Degree");
            return;
        }

        // Save data in localStorage
        const studentData = {
            fname,
            lname,
            mobile,
            favLang: favLang.value,
            degree: degree.value
        };

        localStorage.setItem("studentData", JSON.stringify(studentData));

        alert("✅ Data Saved Successfully (localStorage)");

        submitForm.submit();
    });
});
