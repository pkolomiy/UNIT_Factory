const newElem = (elemName, className = null, innerHTML = null) => {
  const el = document.createElement(elemName);
  if (className) {
    el.className = className;
  }
  el.innerHTML = innerHTML;
  return el
};

let currentMove = (color = null) => {
  const currentMoveDiv = document.querySelector('#current_move');
  if (color === 'red' || color === 'blue') {
    currentMoveDiv.classList.remove({'red': 'blue', 'blue': 'red'}[color]);
    currentMoveDiv.classList.add(color);
  } else if (currentMoveDiv.classList.contains('red')) {
    return 'red'
  } else if (currentMoveDiv.classList.contains('blue')) {
    return 'blue'
  }
  return color
};

let AITips = true;
let AIMode = true;

let cellClick = selectCell;
const maxMoves = 250;
const maxDepth = 15;

const boardWidth = 19;
const boardHeight = 19;
