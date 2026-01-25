// Animate skill bars & counters
window.onload = () => {
    document.querySelectorAll(".fill").forEach(bar => {
        bar.style.width = bar.dataset.width;
    });

    document.querySelectorAll(".count").forEach(counter => {
        let target = +counter.dataset.target;
        let current = 0;

        let interval = setInterval(() => {
            current++;
            counter.textContent = current;
            if (current === target) clearInterval(interval);
        }, 20);
    });
};

// Dark mode
const themeBtn = document.getElementById("themeBtn");
themeBtn.onclick = () => {
    document.body.classList.toggle("dark");
    localStorage.setItem("theme",
        document.body.classList.contains("dark") ? "dark" : "light"
    );
};

// Load theme
if (localStorage.getItem("theme") === "dark") {
    document.body.classList.add("dark");
}

// Scroll to top
const topBtn = document.getElementById("topBtn");
window.onscroll = () => {
    topBtn.style.display = window.scrollY > 300 ? "block" : "none";
};

topBtn.onclick = () => {
    window.scrollTo({ top: 0, behavior: "smooth" });
};
