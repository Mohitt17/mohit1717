import { useState } from "react";
import { Link } from "react-router-dom";

function ForgotPassword() {
  const [email, setEmail] = useState("");
  const [message, setMessage] = useState("");

  const handleSubmit = (e) => {
    e.preventDefault();

    if (!email) {
      setMessage("Please enter your email");
      return;
    }

    // In real apps, API call happens here
    setMessage("Password reset link has been sent to your email (demo)");
  };

  return (
    <div className="container">
      <form className="login-box" onSubmit={handleSubmit}>
        <h2>Forgot Password</h2>

        {message && <p className="error">{message}</p>}

        <input
          type="email"
          placeholder="Enter your registered email"
          value={email}
          onChange={(e) => setEmail(e.target.value)}
        />

        <button type="submit">Send Reset Link</button>

        <p className="signup-text">
          Back to <Link to="/login">Login</Link>
        </p>
      </form>
    </div>
  );
}

export default ForgotPassword;