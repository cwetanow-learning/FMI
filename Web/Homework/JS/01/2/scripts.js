function ajax(url, method, body, success, error) {
  body = body || {};

  body = JSON.stringify(body);

  var xhr = new XMLHttpRequest();

  xhr.onload = function () {
    if (xhr.status === 200) {
      success(xhr.responseText);
    } else {
      error(xhr.responseText);
    }
  };

  xhr.open(method, url, true);
  xhr.send(body);
}

const onSuccess = (response) => {
  console.log(response);
}

const onError = (error) => {
  console.log(error);
}

document.querySelector("form")
  .addEventListener("submit", function (e) {
    e.preventDefault();

    const url = 'http://localhost:10202/api/login'; // some random url...

    const username = document.getElementById('username').value;
    const password = document.getElementById('password').value;
    const confirmPassword = document.getElementById('confirmPassword').value;

    const body = {
      username,
      password,
      confirmPassword
    }

    ajax(url, 'POST', body, onSuccess, onError);
  });