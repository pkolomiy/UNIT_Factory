function showWinner(res) {
  if (res.win) {
    res.win.forEach(({y, x}) => {
      const cell = document.querySelector(`#y${y}x${x}`);
      cell.classList.toggle('win');
    })
  } else if (res.win_by_capture !== 0) {
    document.querySelector('.capture-rule')
      .querySelector({1: '.blue', 2: '.red'}[res.win_by_capture])
      .classList.toggle('win')
  }
}
