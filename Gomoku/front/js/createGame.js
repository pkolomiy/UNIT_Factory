(async () => {
  let res = await fetch('/api/board');
  res = await res.json();

  // Set Sidebar
  AIMode = res.ai_mode;
  AITips = res.ai_tips;
  const aiTips = document.querySelector('#ai_tips');
  [aiTips.checked, aiTips.disabled] = [res.ai_tips, res.ai_mode];
  document.querySelector('#double_three').checked = res.double_three;
  document.querySelector('#ai_mode').checked = res.ai_mode;
  document.querySelector('#capture_rule').checked = res.capture_rule;
  document.querySelector('.capture-rule').style.display = res.capture_rule ? 'flex' : 'none';

  const depthSelector = document.querySelector('#depth');
  for (let i = 1; i <= maxDepth; i++) {
    const option = newElem('option', null, i.toString());
    depthSelector.appendChild(option);
  }
  depthSelector.value = res.depth;

  const movesSelector = document.querySelector('#moves');
  for (let i = 1; i <= maxMoves; i++) {
    const option = newElem('option', null, i.toString());
    movesSelector.appendChild(option);
  }
  movesSelector.value = res.moves;

  if ((document.querySelector('#difficulty_level').selectedIndex = (() => {
    const lvl = {'213': 0, '76': 1, '2503': 2}[`${res.moves}${res.depth}`];
    return lvl !== undefined ? lvl : 3;
  })()) !== 3) {
    depthSelector.parentElement.style.display = 'none';
    movesSelector.parentElement.style.display = 'none';
  }


  document.querySelector('#debug_mode').checked = res.debug_mode;
  if (!res.debug_mode) {
    document.querySelector('.debug-wrapper').style.display = 'none';
  }

  // Set Board
  const boardDiv = document.querySelector('#board');

  for (let y = 0; y < boardHeight; y++) {
    const row = newElem('div', 'row');

    for (let x = 0; x < boardWidth; x++) {
      const cell = newElem('div', 'cell');
      cell.id = `y${y}x${x}`;
      cell.onclick = function () {
        if (cellClick &&
          this.classList.value.search('blue') === -1 &&
          this.classList.value.search('red') === -1) {
          document.querySelectorAll('.tip').forEach(cell => cell.classList.remove('tip'));
          const currentColor = currentMove();
          currentMove({'red': 'blue', 'blue': 'red'}[currentColor]);
          this.classList.toggle(currentColor);
          cellClick(y, x, currentColor);
        }
      };
      cell.appendChild(newElem('span'));
      row.appendChild(cell);
    }

    boardDiv.appendChild(row);
  }
})();

function firstMove(color) {
  document.querySelector('#turn-order').style.display = 'none';
  currentMove(color);
  if (document.querySelector('#ai_mode').checked && color === 'red') {
    selectCell(parseInt(boardHeight / 2), parseInt(boardWidth / 2), 'red');
  }
}
