const validateUsername = (username) => {
  const errorElement = document.getElementById('username-error');

  let regex = /^[a-zA-Z0-9_]+$/;
  if (username.length < 3 || username.length > 10 || username.search(regex) == -1) {
    errorElement.style.display = "block";

    return false;
  }

  errorElement.style.display = "none";
  return true;
}

const validatePassword = (password) => {
  const errorElement = document.getElementById('password-error');

  const numbers = password.match(/\d+/g);
  const uppers = password.match(/[A-Z]/);
  const lowers = password.match(/[a-z]/);

  if (password.length < 6 || !numbers || !uppers || !lowers) {
    errorElement.style.display = "block";

    return false;
  }

  errorElement.style.display = "none";
  return true;
}

const validateConfirmPassword = (confirmPassword, password) => {
  const errorElement = document.getElementById('confirm-password-error');

  if (confirmPassword !== password) {
    errorElement.style.display = "block";

    return false;
  }

  errorElement.style.display = "none";
  return true;
}

document.querySelector("form")
  .addEventListener("submit", function (e) {
    let isValid = true;

    const username = document.getElementById('username').value;
    isValid = validateUsername(username);

    const password = document.getElementById('password').value;
    isValid = validatePassword(password);

    const confirmPassword = document.getElementById('confirmPassword').value;
    isValid = validateConfirmPassword(confirmPassword);

    if (!isValid) {
      e.preventDefault();
    }
  });