function resetGame() {
  fetch(`/api/reset`)
    .then(response => response.json())
    .then(data => resetBoard(data))
    .catch(console.error)
}

function resetBoard(data) {
  document.querySelector('.notification').innerHTML = null;
  document.querySelector('.debug-panel').innerHTML = null;
  document.querySelector('#blue_capture').innerHTML = '0';
  document.querySelector('#red_capture').innerHTML = '0';
  document.querySelector('#ai_mode').disabled = false;
  document.querySelector('#capture_rule').disabled = false;
  document.querySelectorAll('.capture-rule .win')
    .forEach(el => el.classList.remove('win'));

  document.querySelector('#turn-order').style.display = 'flex';

  for (let y = 0; y < boardHeight; y++) {
    for (let x = 0; x < boardWidth; x++) {
      const cell = document.querySelector(`#y${y}x${x}`);
      cell.className = 'cell';
      if (data[y][x] === 1) {
        cell.classList.toggle('blue');
      } else if (data[y][x] === 2) {
        cell.classList.toggle('red');
      }
    }
  }

  cellClick = selectCell;
}
