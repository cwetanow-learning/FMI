calculateFrogs = (n) => {
  const size = n * 2 + 1;

  const frogs = [];

  for (var index = 0; index < n; index++) {
    frogs[index] = '>';
  }

  frogs[n] = '_';

  for (var index = 0; index < n; index++) {
    frogs[index + n + 1] = '<';
  }

  getNextMoves = (frogArray) => {
    const emptyIndex = frogArray.indexOf('_');
    const result = [];

    if (frogArray[emptyIndex - 1] && frogArray[emptyIndex - 1] === '>') {
      const move = [...frogArray];
      move[emptyIndex] = '>';
      move[emptyIndex - 1] = '_';

      result.push(move);
    }

    if (frogArray[emptyIndex - 2] && frogArray[emptyIndex - 2] === '>') {
      const move = [...frogArray];
      move[emptyIndex] = '>';
      move[emptyIndex - 2] = '_';

      result.push(move);
    }

    if (frogArray[emptyIndex + 1] && frogArray[emptyIndex + 1] === '<') {
      const move = [...frogArray];
      move[emptyIndex] = '<';
      move[emptyIndex + 1] = '_';

      result.push(move);
    }

    if (frogArray[emptyIndex + 2] && frogArray[emptyIndex + 2] === '<') {
      const move = [...frogArray];
      move[emptyIndex] = '<';
      move[emptyIndex + 2] = '_';

      result.push(move);
    }

    return result;
  }

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

  const result = [];

  dfs = (arr) => {
    if (isSolution(arr)) {
      result.push(arr);
      return true;
    }

    const nextMoves = getNextMoves(arr);

    for (var index = 0; index < nextMoves.length; index++) {
      if (dfs(nextMoves[index])) {
        result.push(arr);
        return true;
      }
    }

    return false;
  }

  dfs(frogs, n);

  while (result.length) {
    console.log(result.pop());
  }
}

console.log('Enter n:')

var stdin = process.openStdin();

stdin.addListener("data", function (input) {
  const n = +input.toString().trim();

  calculateFrogs(n);
});