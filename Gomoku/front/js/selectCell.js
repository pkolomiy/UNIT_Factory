function selectCell(selectedY, selectedX, color) {
  document.querySelector('#capture_rule').disabled = true;
  document.querySelector('#ai_mode').disabled = true;
  cellClick = null;

  fetch(`/api/move?y=${selectedY}&x=${selectedX}&color=${color}`)
    .then(response => response.json())
    .then(data => {
      const {blue_pos, red_pos, win, notification} = data;
      document.querySelector('#blue_capture').innerHTML = data.captures[1];
      document.querySelector('#red_capture').innerHTML = data.captures[2];

      addNotification(notification);

      const capture = (pos, className) => {
        const cell1 = document.querySelector(`#y${pos[0].y}x${pos[0].x}`);
        const cell2 = document.querySelector(`#y${pos[1].y}x${pos[1].x}`);
        cell1.classList.toggle(className);
        cell2.classList.toggle(className);
      };

      const placePos = (blue_pos, red_pos) => {
        if (AIMode) {
          document.querySelector(`#y${red_pos.y}x${red_pos.x}`)
            .classList.toggle('red');
        } else if (AITips && !win && !data.win_by_capture) {
          document.querySelector(`#y${red_pos.y}x${red_pos.x}`)
            .classList.toggle('tip');
        }
        if (AIMode && red_pos.capture) {
          capture(red_pos.capture.pos, 'blue');
        }
        if (blue_pos.capture) {
          capture(blue_pos.capture.pos, currentMove());
        }
      };

      if (data.debug) {
        updateDebug(data.debug);
      }

      if (win !== undefined && win !== null) {
        if (red_pos) {
          placePos(blue_pos, red_pos);
        }
        showWinner(data);
      } else if (data.win_by_capture) {
        if (red_pos) {
          placePos(blue_pos, red_pos)
        } else {
          capture(blue_pos.capture.pos, currentMove());
        }
        showWinner(data);
      } else if (!red_pos) {
        document.querySelector(`#y${selectedY}x${selectedX}`)
          .classList.toggle(color);
        if (!AIMode) {
          currentMove({'red': 'blue', 'blue': 'red'}[currentMove()]);
        }
      } else {
        placePos(blue_pos, red_pos);
      }

      if (AIMode) {
        currentMove({'red': 'blue', 'blue': 'red'}[currentMove()]);
      }

      if (!win && !data.win_by_capture) {
        cellClick = selectCell;
      }

    })
    .catch(console.error)
}
