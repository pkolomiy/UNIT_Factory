function changeDoubleThreeRule() {
  const doubleThree = document.querySelector('#double_three');

  fetch(`/api/settings/double-three?check=${doubleThree.checked}`)
    .catch(console.error)
}

function changeCaptureRule() {
  const capture = document.querySelector('#capture_rule');
  document.querySelector('.capture-rule').style.display = capture.checked ? 'flex' : 'none';

  fetch(`/api/settings/capture?check=${capture.checked}`)
    .catch(console.error)
}

function changeAIMode() {
  const aiMode = document.querySelector('#ai_mode');
  document.querySelector('#ai_tips').disabled = aiMode.checked;
  AIMode = aiMode.checked;

  fetch(`/api/settings/ai-mode?check=${aiMode.checked}`)
    .catch(console.error)
}

function changeAITips() {
  const aiTips = document.querySelector('#ai_tips');
  AITips = aiTips.checked;

  fetch(`/api/settings/ai-tips?check=${aiTips.checked}`)
    .catch(console.error)
}

function changeDifficultyLevel() {
  let level = document.querySelector('#difficulty_level');
  const depth = document.querySelector('#depth');
  const moves = document.querySelector('#moves');
  level = level.options[level.selectedIndex].value;
  if (level === 'custom') {
    depth.parentElement.style.display = 'flex';
    moves.parentElement.style.display = 'flex';
  } else {
    depth.parentElement.style.display = 'none';
    moves.parentElement.style.display = 'none';
    [depth.selectedIndex, moves.selectedIndex] = {
      'easy': [12, 1],
      'medium': [5, 6],
      'hard': [2, 249],
    }[level];
    changeDifficulty();
  }
}

function changeDifficulty() {
  const depth = document.querySelector('#depth');
  const moves = document.querySelector('#moves');
  const depthValue = depth.options[depth.selectedIndex].value;
  const movesValue = moves.options[moves.selectedIndex].value;

  fetch(`/api/settings/difficulty?depth=${depthValue}&moves=${movesValue}`)
    .catch(console.error)
}

function changeDebugMode() {
  const debug = document.querySelector('#debug_mode');
  document.querySelector('.debug-wrapper').style.display = debug.checked ? 'flex' : 'none';

  fetch(`/api/settings/debug?check=${debug.checked}`)
    .catch(console.error)
}

