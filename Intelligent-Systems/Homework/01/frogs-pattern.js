calculateFrogs = (n) => {
  isSolution = (arr) => {
    if (arr[n] !== '_') {
      return false;
    }

    for (var index = 0; index < n; index++) {
      if (arr[index] !== '<') {
        return false;
      }
    }

    for (var index = 0; index < n; index++) {
      if (arr[index + n + 1] !== '>') {
        return false;
      }
    }

    return true;
  }

  const size = n * 2 + 1;

  const frogs = [];

  for (var index = 0; index < n; index++) {
    frogs[index] = '>';
  }

  frogs[n] = '_';

  for (var index = 0; index < n; index++) {
    frogs[index + n + 1] = '<';
  }

  let counter = 1;
  let isMovingLeft = false;
  let middleCounter = 3;
  let hasPassedMiddle = false;

  while (true) {
    if (isSolution(frogs)) {
      break;
    }

    for (var i = 0; i < counter; i++) {
      console.log(frogs);

      const emptyIndex = frogs.indexOf('_');

      if (isMovingLeft) {
        if (frogs[emptyIndex + 1] && frogs[emptyIndex + 1] === '<') {
          frogs[emptyIndex] = '<';
          frogs[emptyIndex + 1] = '_';
        } else if (frogs[emptyIndex + 2] && frogs[emptyIndex + 2] === '<') {
          frogs[emptyIndex] = '<';
          frogs[emptyIndex + 2] = '_';
        }
      } else {
        if (frogs[emptyIndex - 1] && frogs[emptyIndex - 1] === '>') {
          frogs[emptyIndex] = '>';
          frogs[emptyIndex - 1] = '_';
        } else if (frogs[emptyIndex - 2] && frogs[emptyIndex - 2] === '>') {
          frogs[emptyIndex] = '>';
          frogs[emptyIndex - 2] = '_';
        }
      }
    }

    isMovingLeft = !isMovingLeft;

    if (!middleCounter) {
      hasPassedMiddle = true;
    } else if (counter === n) {
      --middleCounter;
      continue;
    }

    if (hasPassedMiddle) {
      --counter;
    } else {
      ++counter;
    }
  }
}

console.log('Enter n:')

var stdin = process.openStdin();

stdin.addListener("data", function (input) {
  const n = +input.toString().trim();

  calculateFrogs(n);
});