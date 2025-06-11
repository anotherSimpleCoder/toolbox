-- This file can be loaded by calling `lua require('plugins')` from your init.vim

-- Only required if you have packer configured as `opt`
vim.cmd [[packadd packer.nvim]]

return require('packer').startup(function(use)
  	-- Packer can manage itself
	use 'wbthomason/packer.nvim'

	use({
		'marko-cerovac/material.nvim',
		as = 'material',
		config = function()
			vim.cmd 'colorscheme material'
		end
	})

	use("nvim-treesitter/nvim-treesitter", {run = ":TSUpdate"})
	use "neovim/nvim-lspconfig"
	use("hrsh7th/cmp-nvim-lsp")
	use("hrsh7th/cmp-buffer")
	use("hrsh7th/cmp-path")
	use("hrsh7th/cmp-cmdline")
	use("hrsh7th/nvim-cmp")
end)
