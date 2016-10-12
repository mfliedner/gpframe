class UsersController < ApplicationController
  def create
		@user = User.new(user_params)

		if @user.save
			# login(@user)
			render "home/index"
		else
			render json: @user.errors, status: 422
		end
	end

	private

	def user_params
		params.require(:user).permit(:email, :password, :name, :uid, :provider)
	end
end
