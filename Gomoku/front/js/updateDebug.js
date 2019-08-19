function updateDebug(debugObj) {
  const panel = document.querySelector('.debug-panel');
  panel.innerHTML = null;

  const updateBoard = (debugBoard, mainDebug, board) => {
    debugBoard.appendChild(newElem('div', 'score-num', `bestScore: ${mainDebug.best_score}`));
    debugBoard.appendChild(newElem('div', 'score-num', `turnScore: ${mainDebug.turn_score}`));

    for (let y = 0; y < boardHeight; y++) {
      const row = newElem('div', 'row');

      for (let x = 0; x < boardWidth; x++) {
        const cell = newElem('div', 'cell small');
        const mainCell = board.querySelectorAll('.row')[y].querySelectorAll('.cell')[x];

        cell.appendChild(newElem('span'));

        if (mainCell.classList.contains('red')) {
          cell.classList.toggle('red');
        } else if (mainCell.classList.contains('blue')) {
          cell.classList.toggle('blue');
        }
        if (mainDebug.pos.y === y && mainDebug.pos.x === x) {
          if (mainDebug.player === 1) {
            cell.classList.toggle('blue');
          } else if (mainDebug.player === 2) {
            cell.classList.toggle('red');
          }
        }
        row.appendChild(cell);
      }

      debugBoard.appendChild(row);
    }

    if (mainDebug.pos.capture) {
      [first, second] = mainDebug.pos.capture.pos;
      debugBoard.querySelectorAll('.row')[first.y]
        .querySelectorAll('.cell')[first.x]
        .className = 'cell small';
      debugBoard.querySelectorAll('.row')[second.y]
        .querySelectorAll('.cell')[second.x]
        .className = 'cell small';
    }

  };

  const addDebug = (mainDebug, debugArr, mainIndex, board) => {
    const debugElDiv = newElem('div', 'debug-el');
    const scores = newElem('div', 'scores');

    debugArr.forEach((debugEl, index) => {
      const scoreButton = newElem('button', 'score-button', debugEl.best_score);
      scoreButton.onclick = function () {
        this.parentElement.querySelector('.active').classList.remove('active');
        this.classList.add('active');
        (function removeSibling(el) {
          if (el) {
            removeSibling(el.nextSibling);
            el.remove();
          }
        })(this.parentElement.parentElement.nextSibling);
        const debugBoard = this.parentElement.parentElement.querySelector('.board');
        debugBoard.innerHTML = null;
        updateBoard(debugBoard, debugEl, board);
        if (debugEl.index !== -1) {
          addDebug(debugEl.debug[debugEl.index], debugEl.debug, debugEl.index, debugBoard);
        }
      };
      if (mainIndex === index) {
        scoreButton.classList.add('active');
      }
      scores.appendChild(scoreButton);
    });

    const debugBoard = newElem('div', 'board');

    updateBoard(debugBoard, mainDebug, board);

    debugElDiv.appendChild(scores);
    debugElDiv.appendChild(debugBoard);

    panel.appendChild(debugElDiv);

    if (mainDebug.index !== -1) {
      addDebug(mainDebug.debug[mainDebug.index], mainDebug.debug, mainDebug.index, debugBoard);
    }
  };

  let board = document.querySelector('#board');
  board = board.cloneNode(true);
  if (debugObj.index !== -1) {
    addDebug(debugObj.debug[debugObj.index], debugObj.debug, debugObj.index, board);
  }
}
