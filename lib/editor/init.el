(package-initialize)

(setq inhibit-startup-message t)

(setq make-backup-files nil)

(setq delete-auto-save-files t)

(setq-default tab-width 4 indent-tabs-mode nil)

(setq eol-mnemonic-dos "(CRLF)")
(setq eol-mnemonic-mac "(CR)")
(setq eol-mnemonic-unix "(LF)")

(tool-bar-mode -1)
(menu-bar-mode -1)

(column-number-mode t)
(global-linum-mode t)
(blink-cursor-mode t)
(show-paren-mode 1)
(setq mouse-wheel-scroll-amount '(1 ((shift) . 5)))
(load-theme 'monokai t)

